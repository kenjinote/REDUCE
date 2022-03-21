#include "xincs.h"
#include "fxver.h"
#include "fxdefs.h"
#include "FXHash.h"
#include "FXStream.h"
#include "FXTextCodec.h"
#include "FXCP1255Codec.h"

namespace FX {

FXIMPLEMENT(FXCP1255Codec,FXTextCodec,NULL,0)


//// Created by codec tool on 03/25/2005 from: CP1255.TXT ////
static const unsigned short forward_data[256]={
   0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    10,   11,   12,   13,   14,   15,
   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,
   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   99,   100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
   112,  113,  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,
   8364, 65533, 8218, 402,  8222, 8230, 8224, 8225, 710,  8240, 65533, 8249, 65533, 65533, 65533, 65533,
   65533, 8216, 8217, 8220, 8221, 8226, 8211, 8212, 732,  8482, 65533, 8250, 65533, 65533, 65533, 65533,
   160,  161,  162,  163,  8362, 165,  166,  167,  168,  169,  215,  171,  172,  173,  174,  175,
   176,  177,  178,  179,  180,  181,  182,  183,  184,  185,  247,  187,  188,  189,  190,  191,
   1456, 1457, 1458, 1459, 1460, 1461, 1462, 1463, 1464, 1465, 65533, 1467, 1468, 1469, 1470, 1471,
   1472, 1473, 1474, 1475, 1520, 1521, 1522, 1523, 1524, 65533, 65533, 65533, 65533, 65533, 65533, 65533,
   1488, 1489, 1490, 1491, 1492, 1493, 1494, 1495, 1496, 1497, 1498, 1499, 1500, 1501, 1502, 1503,
   1504, 1505, 1506, 1507, 1508, 1509, 1510, 1511, 1512, 1513, 1514, 65533, 65533, 8206, 8207, 65533,
  };


static const unsigned char reverse_plane[17]={
  0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
  };

static const unsigned char reverse_pages[73]={
  0,  46, 78, 78, 78, 78, 78, 78, 142,78, 78, 78, 78, 78, 78, 78,
  78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
  78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
  78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
  78, 78, 78, 78, 78, 78, 78, 78, 78,
  };

static const unsigned short reverse_block[206]={
  0,   16,  32,  48,  64,  80,  96,  112, 128, 128, 144, 160, 128, 176, 128, 185,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 199, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 209, 216, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 232, 248, 264, 280, 296, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 301, 317,
  333, 349, 128, 128, 128, 128, 128, 128, 360, 128, 128, 128, 128, 128, 128, 128,
  374, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  };

static const unsigned char reverse_data[390]={
   0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    10,   11,   12,   13,   14,   15,
   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,
   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   99,   100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
   112,  113,  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,
   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   160,  161,  162,  163,  26,   165,  166,  167,  168,  169,  26,   171,  172,  173,  174,  175,
   176,  177,  178,  179,  180,  181,  182,  183,  184,  185,  26,   187,  188,  189,  190,  191,
   26,   26,   26,   26,   26,   26,   26,   170,  26,   26,   26,   26,   26,   26,   26,   26,
   186,  26,   26,   26,   26,   26,   26,   26,   26,   131,  26,   26,   26,   26,   26,   26,
   26,   26,   26,   26,   26,   26,   26,   136,  26,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   26,   26,   152,  26,   26,   26,   192,  193,  194,  195,  196,  197,  198,  199,
   200,  201,  26,   203,  204,  205,  206,  207,  208,  209,  210,  211,  26,   26,   26,   26,
   26,   26,   26,   26,   26,   26,   26,   26,   224,  225,  226,  227,  228,  229,  230,  231,
   232,  233,  234,  235,  236,  237,  238,  239,  240,  241,  242,  243,  244,  245,  246,  247,
   248,  249,  250,  26,   26,   26,   26,   26,   212,  213,  214,  215,  216,  26,   26,   26,
   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   253,  254,  26,   26,   26,
   150,  151,  26,   26,   26,   145,  146,  130,  26,   147,  148,  132,  26,   134,  135,  149,
   26,   26,   26,   133,  26,   26,   26,   26,   26,   26,   26,   26,   26,   137,  26,   26,
   26,   26,   26,   26,   26,   26,   139,  155,  26,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   164,  26,   128,  26,   26,   26,   153,  26,   26,   26,   26,   26,   26,   26,
   26,   26,   26,   26,   26,   26,
  };


FXint FXCP1255Codec::mb2wc(FXwchar& wc,const FXchar* src,FXint nsrc) const {
  if(nsrc<1) return -1;
  wc=forward_data[(FXuchar)src[0]];
  return 1;
  }


FXint FXCP1255Codec::wc2mb(FXchar* dst,FXint ndst,FXwchar wc) const {
  if(ndst<1) return -1;
  dst[0]=reverse_data[reverse_block[reverse_pages[reverse_plane[wc>>16]+((wc>>10)&63)]+((wc>>4)&63)]+(wc&15)];
  return 1;
  }

FXint FXCP1255Codec::mibEnum() const {
  return 2255;
  }


const FXchar* FXCP1255Codec::name() const {
  return "windows-1255";
  }


const FXchar* FXCP1255Codec::mimeName() const {
  return "windows-1255";
  }


const FXchar* const* FXCP1255Codec::aliases() const {
  static const FXchar *const list[]={"microsoft-cp1255","windows-1255","cp1255",NULL};
  return list;
  }

}

