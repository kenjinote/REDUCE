/********************************************************************************
*                                                                               *
*                   S U N   R A S T E R   I m a g e   O b j e c t               *
*                                                                               *
*********************************************************************************
* Copyright (C) 2004,2006 by Jeroen van der Zijp.   All Rights Reserved.        *
*********************************************************************************
* This library is free software; you can redistribute it and/or                 *
* modify it under the terms of the GNU Lesser General Public                    *
* License as published by the Free Software Foundation; either                  *
* version 2.1 of the License, or (at your option) any later version.            *
*                                                                               *
* This library is distributed in the hope that it will be useful,               *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU             *
* Lesser General Public License for more details.                               *
*                                                                               *
* You should have received a copy of the GNU Lesser General Public              *
* License along with this library; if not, write to the Free Software           *
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.    *
*********************************************************************************
* $Id: FXRASIcon.h 3297 2015-12-14 20:30:04Z arthurcnorman $                          *
********************************************************************************/
#ifndef FXRASICON_H
#define FXRASICON_H

#ifndef FXICON_H
#include "FXIcon.h"
#endif

namespace FX {


/// SUN Raster Image format icon
class FXAPI FXRASIcon : public FXIcon {
  FXDECLARE(FXRASIcon)
protected:
  FXRASIcon(){}
private:
  FXRASIcon(const FXRASIcon&);
  FXRASIcon &operator=(const FXRASIcon&);
public:
  static const FXchar fileExt[];
  static const FXchar mimeType[];
public:

  /// Construct icon from memory stream formatted in SUN Raster Image format
  FXRASIcon(FXApp* a,const void *pix=NULL,FXColor clr=FXRGB(192,192,192),FXuint opts=0,FXint w=1,FXint h=1);

  /// Save pixels into stream in SUN Raster Image format
  virtual bool savePixels(FXStream& store) const;

  /// Load pixels from stream in SUN Raster Image format
  virtual bool loadPixels(FXStream& store);

  /// Destroy icon
  virtual ~FXRASIcon();
  };


/**
* Check if stream contains a RAS, return TRUE if so.
*/
extern FXAPI bool fxcheckRAS(FXStream& store);


/**
* Load an SUN Raster Image format file from a stream.
* Upon successful return, the pixel array and size are returned.
* If an error occurred, the pixel array is set to NULL.
*/
extern FXAPI bool fxloadRAS(FXStream& store,FXColor*& data,FXint& width,FXint& height);


/**
* Save an SUN Raster Image format file to a stream.
*/
extern FXAPI bool fxsaveRAS(FXStream& store,const FXColor *data,FXint width,FXint height);

}

#endif
