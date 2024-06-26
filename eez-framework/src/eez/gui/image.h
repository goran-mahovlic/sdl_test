/*
 * eez-framework
 *
 * MIT License
 * Copyright 2024 Envox d.o.o.
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <stdint.h>

struct Image {
    uint32_t width;
    uint32_t height;
    uint32_t bpp;
    uint32_t lineOffset;
    uint8_t *pixels;
};

enum ImageDecodeResult {
    IMAGE_DECODE_OK,
    IMAGE_DECODE_ERR_FILE_NOT_FOUND,
    IMAGE_DECODE_ERR_FILE_READ,
    IMAGE_DECODE_ERR_NOT_ENOUGH_MEMORY,
    IMAGE_DECODE_ERR_DECODE,
    IMAGE_DECODE_ERR_IMAGE_SIZE_UNSUPPORTED
};

ImageDecodeResult imageDecode(const char *filePath, Image *image);
