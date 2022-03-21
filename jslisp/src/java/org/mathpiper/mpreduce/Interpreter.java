/**************************************************************************
 * Copyright (C) 2011 Ted Kosan                                           *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/
package org.mathpiper.mpreduce;

import com.google.gwt.core.client.EntryPoint;
import com.google.gwt.core.client.GWT;
import com.google.gwt.core.client.JavaScriptObject;
import com.google.gwt.core.client.Scheduler;
import com.google.gwt.core.client.Scheduler.RepeatingCommand;
import java.io.IOException;


import org.mathpiper.mpreduce.io.streams.InputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import org.mathpiper.mpreduce.datatypes.Cons;
import org.mathpiper.mpreduce.datatypes.LispString;
import org.mathpiper.mpreduce.functions.functionwithenvironment.Bytecode;
import org.mathpiper.mpreduce.functions.lisp.LispFunction;
import org.mathpiper.mpreduce.io.streams.LispOutputString;
import org.mathpiper.mpreduce.io.streams.LispStream;
import org.mathpiper.mpreduce.numbers.LispSmallInteger;
import org.mathpiper.mpreduce.packagedatastore.PDS;
import org.mathpiper.mpreduce.packagedatastore.PDSInputStream;
import org.mathpiper.mpreduce.special.SpecialFunction;
import org.mathpiper.mpreduce.symbols.Symbol;
import org.mathpiper.mpreduce.zip.GZIPInputStream;

public class Interpreter implements EntryPoint {

    Jlisp jlisp;
    private static Interpreter InterpreterInstance = null;
    private String startMessage;
    private String prompt;
    private String sendString = null;
    InputStream in;
    //Lisp out, my in.
    LispStream out;

    public Interpreter() {

        InterpreterInstance = this;

    }//end constructor.

    public String initialize() {

        String result = "";

        jlisp = new Jlisp();

        try {

            in = new InterpreterInputStream(this);

            out = new LispOutputString();

            final String[] args = new String[0];

            jlisp.startup(args, in, out);

            jlisp.initialize();

            result = evaluate("off int; on errcont;");


        } catch (Throwable t) {
            t.printStackTrace();

            result = t.getMessage();

        } finally {
            return result;
        }
    }

    public String getStartMessage() {
        return startMessage;
    }//end method.

    public String evaluate(String send) {

        send = send.trim();

        if (send.equals("")) {
            return ("No Input Sumbitted.");
        }

        while (send.endsWith(";;")) {
            send = send.substring(0, send.length() - 1);
        }

        if (!send.endsWith(";") && !send.endsWith("$")) {
            send = send + ";";
        }

        send = send + "end;";


        try {

            sendString = send;

            in.close();

            jlisp.evaluate();

        } catch (Throwable t) {
            out.println();
            out.println(t.getMessage());
        } finally {
            String result;

            out.flush();

            result = out.toString();

            out.close();

            return result;
        }

    }//end evaluate.

    public void interruptEvaluation() {
        try {

            jlisp.interruptEvaluation = true;

        } catch (Throwable e) {
            //Each excpetion.
        }
    }

    //Lisp in, my out.
    class InterpreterInputStream extends InputStream {

        private ArrayList expressions = new ArrayList();
        private Iterator expressionsIterator;
        private Interpreter interpreter;
        public int pos, len;
        private String result;

        InterpreterInputStream(Interpreter interpreter) {
            this.interpreter = interpreter;

            sendString = null;
        }

        public int available() {
            if (sendString != null) {
                return 1;
            } else {
                return 0;
            }
        }

        public void close() {
            pos = 0;
            len = sendString.length();
        }

        public boolean markSupported() {
            return false;
        }

        public int read() {

            if (pos == len) {
                sendString = null;
                return (int) -1;
            } else {
                int i = (int) sendString.charAt(pos++);
                return i;
            }
        }
    }//end method.

    private String test() {
        String result = "";

        try {

            //result = evaluate("2+2");

            result = evaluate("(X-Y)^100");
            System.out.println(result);

            result = evaluate("load ineq");
            System.out.println(result);

            result = evaluate("ineq_solve((x - 1)/(x + 2) > 0,x);");
            System.out.println(result);

        } catch (Throwable t) {
            System.out.println(t.getMessage());
        }

        return result;



    }//end method.

//---------
    public static String casVersion() {
        return "MPReduceJS version " + InterpreterInstance.version();
    }

    public static native void exportCasVersionMethod() /*-{
    $wnd.casVersion = function(){
    return @org.mathpiper.mpreduce.Interpreter::casVersion()();
    }
    }-*/;

//---------
    public static String casEvaluate(String send) {
        return InterpreterInstance.evaluate(send);
    }

    public static native void exportEvaluateMethod() /*-{
    $wnd.casEval = function(send){
    return @org.mathpiper.mpreduce.Interpreter::casEvaluate(Ljava/lang/String;)(send);
    }
    }-*/;

//---------
    public static String casInitialize() {
        String result = InterpreterInstance.initialize();

        callCasLoaded();

        return result;
    }


//---------
    public static native void callCasLoaded() /*-{
    $wnd.casLoaded();
    }-*/;
    //---------
    static JavaScriptObject callBackFunction = null;

    public static void casLoadImage() {
        try {

            Scheduler.get().scheduleIncremental(InterpreterInstance.getInitializationExecutor());


        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    public static native void callImageLoadedCallback() /*-{
    callBackFunction();
    }-*/;

//---------
    @Override
    public void onModuleLoad() {

        exportCasVersionMethod();

        exportEvaluateMethod();
        
        casLoadImage();

    }

    public static String version() {
        return Jlisp.version;
    }

    public RepeatingCommand getInitializationExecutor() {
        RepeatingCommand repeatingCommand = new RepeatingCommand() {

            int counter = 0;
            private int loopIndex = 1;

            public boolean execute() {

                boolean returnValue = true;
                // For use while I am re-loading image and also to assist the
                // custom Lisp bytecoded stuff I build a table of all the functions
                // that I have built into this Lisp.
                //
                try {
                    switch (loopIndex) {
                        case 1:
                            LispSmallInteger.preAllocate();  // some small integers treated specially.
                            loopIndex++;
                            break;
                        case 2:
                            Jlisp.builtinFunctions = new HashMap();
                            Jlisp.builtinSpecials = new HashMap();
                            for (int i = 0; i < Jlisp.fns1.builtins.length; i++) {
                                ((LispFunction) Jlisp.fns1.builtins[i][1]).name =
                                        (String) Jlisp.fns1.builtins[i][0];
                                Jlisp.builtinFunctions.put(Jlisp.fns1.builtins[i][0], Jlisp.fns1.builtins[i][1]);
                            }
                            loopIndex++;
                            break;

                        case 3:
                            for (int i = 0; i < Jlisp.fns2.builtins.length; i++) {
                                ((LispFunction) Jlisp.fns2.builtins[i][1]).name =
                                        (String) Jlisp.fns2.builtins[i][0];
                                Jlisp.builtinFunctions.put(Jlisp.fns2.builtins[i][0], Jlisp.fns2.builtins[i][1]);
                            }
                            loopIndex++;
                            break;
                        case 4:
                            for (int i = 0; i < Jlisp.fns3.builtins.length; i++) {
                                ((LispFunction) Jlisp.fns3.builtins[i][1]).name =
                                        (String) Jlisp.fns3.builtins[i][0];
                                Jlisp.builtinFunctions.put(Jlisp.fns3.builtins[i][0], Jlisp.fns3.builtins[i][1]);
                            }
                            loopIndex++;
                            break;
                        case 5:
                            for (int i = 0; i < Jlisp.mpreduceFunctions.builtins.length; i++) {
                                ((LispFunction) Jlisp.mpreduceFunctions.builtins[i][1]).name =
                                        (String) Jlisp.mpreduceFunctions.builtins[i][0];
                                Jlisp.builtinFunctions.put(Jlisp.mpreduceFunctions.builtins[i][0], Jlisp.mpreduceFunctions.builtins[i][1]);
                            }
                            loopIndex++;
                            break;

                        case 6:
                            for (int i = 0; i < Jlisp.specfn.specials.length; i++) {
                                ((SpecialFunction) Jlisp.specfn.specials[i][1]).name =
                                        (String) Jlisp.specfn.specials[i][0];
                                Jlisp.builtinSpecials.put(Jlisp.specfn.specials[i][0], Jlisp.specfn.specials[i][1]);
                            }
                            loopIndex++;
                            break;
                        case 7:
                            Bytecode.setupBuiltins();

                            loopIndex++;
                            break;
                        case 8:
                            loadImageSetup();

                            loopIndex++;
                            break;
                        case 9:
                            if (Jlisp.image.execute() == false) {
                                loopIndex++;
                            }
                            break;
                        case 10:
                            // The next stage is either to create an initial Lisp heap or to
                            // re-load one that had been saved from a previous session. Things are
                            // made MUCH more complicated here because a running Lisp can (under program
                            // control) get itself restarted either in cold or warm-start mode.

                            PDSInputStream ii = null;
                            // I will re-load from the first checkpoint file in the list that has
                            // a HeapImage stored in it.

                            try {
                                ii = new PDSInputStream(Jlisp.image, "HeapImage");
                            } catch (IOException e) {
                                e.printStackTrace();
                            }


                            try {
                                if (ii == null) {
                                    throw new IOException("No valid checkpoint file found");
                                }


                                gzip = new GZIPInputStream(ii);



                                Symbol.symbolCount = Cons.consCount = LispString.stringCount = 0;
                                
                                        Jlisp.idump = gzip;
                                        LispReader.getInstance().preRestore();


                            } catch (Exception e) {
                                throw e;
                            }
                            
                            loopIndex++;
                            break;
                        case 11:
                            if(LispReader.getInstance().incrementalRestore() == false)
                            {
                                loopIndex++;
                            }
                            break;
                        case 12:
                            if (LispReader.getInstance().execute() == false) {
                                loopIndex++;
                            }
                            break;
                        default:
                            if (GWT.isClient()) {
                                casInitialize();
                            } else {
                                initialize();
                            }

                            returnValue = false;

                            break;

                    }//end switch.
                } catch (Exception e) {
                    e.printStackTrace();
                }

                return returnValue;

            }//end execute
        };

        return repeatingCommand;
    }//end method.

    private void loadImageSetup() throws Exception {



//Initialize builtin functions code was here.

        // I may need to display diagnostics before I have finshed setting up
        // streams etc in their proper final form, so I arrange a provisional
        // setting that directs early messages to the terminal.
        //lispIO = lispErr = new LispOutputStream();

        Jlisp.lit[Lit.std_output] = Jlisp.lit[Lit.tr_output] =
                Jlisp.lit[Lit.err_output] = Jlisp.lit[Lit.std_input] =
                Jlisp.lit[Lit.terminal_io] = Jlisp.lit[Lit.debug_io] =
                Jlisp.lit[Lit.query_io] = Symbol.intern("temp-stream");

        Jlisp.standardStreams();

        Jlisp.image = null;

        InputStream is = new ReduceImageInputStream();

        if (is != null) {
            Jlisp.image = new PDS(is);
        } else {
            throw new Exception("Problem loading image.");
        }




    }

    private String getPDSFunctionEnteries() {
        String result;
        try {
            Jlisp.image.print();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            out.flush();
            result = out.toString();
            out.close();
            return result;
        }
    }//end method.
    GZIPInputStream gzip = null;

    public static void main(String[] args) {

        Interpreter mpreduce = new Interpreter();

        try {

            RepeatingCommand builtinFunctionExecutor = mpreduce.getInitializationExecutor();
            while (builtinFunctionExecutor.execute() == true) {
            }



            mpreduce.test();


            //Uncomment the following line to list the compiled functions that are in the package data store.
            //System.out.println(mpreduce.getPDSFunctionEnteries());



            if (mpreduce.gzip != null) {

                mpreduce.gzip.close();

            }
        } catch (Throwable t) {
            t.printStackTrace();
        }





        /*String result = "";
        
        try {
        
        result = mpreduce.evaluate("off nat;");
        System.out.println(result + "\n");
        
        result = mpreduce.evaluate("x^2;");
        System.out.println(result + "\n");
        
        result = mpreduce.evaluate("(X-Y)^100;");
        System.out.println(result + "\n");
        
        
        result = mpreduce.evaluate("2 + 2;");
        System.out.println(result + "\n");
        
        
        result = mpreduce.evaluate("Factorize(100);");
        System.out.println(result + "\n");
        
        } catch (Throwable t) {
        t.printStackTrace();
        } finally {
        }*/




    }
}//end class.

