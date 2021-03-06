/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2015-2016 Mario Luzeiro <mrluzeiro@ua.pt>
 * Copyright (C) 1992-2016 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

 /**
 * @file cimage.h
 * @brief one 8bit-channel image definition
 */

#ifndef CIMAGE_H
#define CIMAGE_H

#include <wx/string.h>

/// Image operation type
enum class IMAGE_OP
{
    RAW,
    ADD,
    SUB,
    DIF,
    MUL,
    AND,
    OR,
    XOR,
    BLEND50,
    MIN,
    MAX
};


/// Image wrap type enumeration
enum class IMAGE_WRAP
{
    ZERO,  ///< Coords that wraps are not evaluated
    CLAMP, ///< Coords are clamped to image size
    WRAP   ///< Coords are wrapped arround
};


/// Filter type enumeration
enum class IMAGE_FILTER
{
    HIPASS,
    GAUSSIAN_BLUR,
    GAUSSIAN_BLUR2,
    INVERT_BLUR,
    CARTOON,
    EMBOSS,
    SHARPEN,
    MELT,
    SOBEL_GX,
    SOBEL_GY,
    BLUR_3X3,
};

/// 5x5 Filter struct parameters
typedef struct {
    signed char    kernel[5][5];
    unsigned int   div;
    unsigned char  offset;
}S_FILTER;


/**
 * CIMAGE
 * manages a 8-bit channel image
 */
class CIMAGE
{

public:

    /**
     * Constructor CIMAGE
     * constructs a CIMAGE based on image size
     * @param aXsize x size
     * @param aYsize y size
     */
    CIMAGE( unsigned int aXsize, unsigned int aYsize );

    /**
     * @brief CIMAGE
     * constructs a CIMAGE based on an existent image. It will copy the image to
     * the new
     * @param aSrcImage
     */
    CIMAGE( const CIMAGE &aSrcImage );

    ~CIMAGE();

    /**
     * Function Setpixel
     * set a value in a pixel position, position is clamped in accord with the
     * current clamp settings
     * @param aX x position
     * @param aY y position
     * @param aValue value to set the pixel
     */
    void Setpixel( int aX, int aY, unsigned char aValue );

    /**
     * Function Getpixel
     * get the pixel value from pixel position, position is clamped in accord with the
     * current clamp settings
     * @param aX x position
     * @param aY y position
     * @return unsigned char - pixel value
     */
    unsigned char Getpixel( int aX, int aY ) const;

    /**
     * @brief hline - Draws an horizontal line
     * @param aXStart - x start position
     * @param aXEnd - x end position
     * @param aY - y positoin
     * @param aValue - value to add
     */
    void Hline( int aXStart, int aXEnd, int aY, unsigned char aValue );

    /**
     * @brief CircleFilled
     * @param aCx
     * @param aCy
     * @param aRadius
     * @param aValue
     */
    void CircleFilled( int aCx, int aCy, int aRadius, unsigned char aValue );

    /**
     * Function CopyFull
     * perform a copy operation, based on operation type.
     * The result destination is the self image class
     * @param aImgA an image input
     * @param aImgB an image input
     * @param aOperation operation to perform
     *  IMAGE_OP::RAW        this <- aImgA
     *  IMAGE_OP::ADD        this <- CLAMP(aImgA + aImgB)
     *  IMAGE_OP::SUB        this <- CLAMP(aImgA - aImgB)
     *  IMAGE_OP::DIF        this <- abs(aImgA - aImgB)
     *  IMAGE_OP::MUL        this <- aImgA * aImgB
     *  IMAGE_OP::AND        this <- aImgA & aImgB
     *  IMAGE_OP::OR         this <- aImgA | aImgB
     *  IMAGE_OP::XOR        this <- aImgA ^ aImgB
     *  IMAGE_OP::BLEND50    this <- (aImgA + aImgB) / 2
     *  IMAGE_OP::MIN        this <- (aImgA < aImgB)?aImgA:aImgB
     *  IMAGE_OP::MAX        this <- (aImgA > aImgB)?aImgA:aImgB
     */
    void CopyFull( const CIMAGE* aImgA, const CIMAGE* aImgB, IMAGE_OP aOperation );

    /**
     * Function Invert
     * invert the values of image this <- (255 - this)
     */
    void Invert();

    /**
     * Function EfxFilter
     * apply a filter to the input image and stores it in the image class
     * this <- FilterType(aInImg)
     * @param aInImg input image
     * @param aFilterType filter type to apply
     */
    void EfxFilter( CIMAGE* aInImg, IMAGE_FILTER aFilterType );

    /**
     * Function SaveAsPNG
     * save image buffer to a PNG file into the working folder.
     * each of RGB channel will have the 8bit-channel from the image.
     * @param aFileName fime name (without extension)
     */
    void SaveAsPNG( const wxString& aFileName ) const;

    /**
     * Function SetPixelsFromNormalizedFloat
     * set the current channel from a float normalized (0.0 - 1.0) buffer
     * this <- CLAMP(NormalizedFloat * 255)
     * @param aNormalizedFloatArray a float array with the same size of the image
     */
    void SetPixelsFromNormalizedFloat( const float * aNormalizedFloatArray );

    /**
     * Function GetBuffer
     * get the image buffer pointer
     * @return unsigned char * - the pointer of the buffer 8bit channel
     */
    unsigned char* GetBuffer() const;

    unsigned int GetWidth() const { return m_width; }
    unsigned int GetHeight() const { return m_height; }
private:

    /**
     * Function wrapCoords
     * calculate the coordinates points in accord with the current clamping settings
     * @param aXo X coordinate to be converted (output)
     * @param aXo Y coordinate to be converted (output)
     * @return bool - true if the coordinates are inside the image, false otherwise
     */
    bool wrapCoords( int *aXo, int *aYo ) const;

    void plot8CircleLines( int aCx, int aCy, int aX, int aY, unsigned char aValue );

private:
    unsigned char*  m_pixels;           ///< buffer to store the image 8bit-channel
    unsigned int    m_width;            ///< width of the image
    unsigned int    m_height;           ///< height of the image
    unsigned int    m_wxh;              ///< width * height precalc value
    IMAGE_WRAP      m_wraping;          ///< current wrapping type
};

#endif   // CIMAGE_H
