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

namespace eez {
namespace gui {

inline font::Font styleGetFont(const Style *style) {
    return font::Font(getFontData(style->font));
}

inline bool styleIsBlink(const Style *style) {
    return style->flags & STYLE_FLAGS_BLINK;
}

void drawBorderAndBackground(int &x1, int &y1, int &x2, int &y2, const Style *style, uint16_t color, bool ignoreLuminocity = false);

void drawText(
    const char *text, int textLength,
    int x, int y, int w, int h,
    const Style *style,
    bool active = false, bool blink = false, bool ignoreLuminocity = false,
    uint16_t *overrideColor = nullptr, uint16_t *overrideBackgroundColor = nullptr,
    uint16_t *overrideActiveColor = nullptr, uint16_t *overrideActiveBackgroundColor = nullptr,
    bool useSmallerFontIfDoesNotFit = false, int cursorPosition = -1, int xScroll = 0,
	bool boolSkipBackground = false
);
int getCharIndexAtPosition(int xPos, const char *text, int textLength, int x, int y, int w, int h, const Style *style);
int getCursorXPosition(int cursorPosition, const char *text, int textLength, int x, int y, int w, int h, const Style *style);

void drawMultilineText(const char *text, int x, int y, int w, int h, const Style *style, bool active, bool blinking, int firstLineIndent, int hangingIndent);
int measureMultilineText(const char *text, int x, int y, int w, int h, const Style *style, int firstLineIndent, int hangingIndent);

void drawBitmap(Image *image, int x, int y, int w, int h, const Style *style, bool active);
void drawRectangle(int x, int y, int w, int h, const Style *style, bool active = false, bool ignoreLuminocity = false, bool invertColors = true);

void drawShadow(int x1, int y1, int x2, int y2);
void expandRectWithShadow(int &x1, int &y1, int &x2, int &y2);

void drawLine(int x1, int y1, int x2, int y2);
void drawAntialiasedLine(int x1, int y1, int x2, int y2);

} // namespace gui
} // namespace eez
