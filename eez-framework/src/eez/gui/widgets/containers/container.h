/*
 * EEZ Modular Firmware
 * Copyright (C) 2015-present, Envox d.o.o.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

namespace eez {
namespace gui {

#define CONTAINER_WIDGET_LAYOUT_STATIC 0
#define CONTAINER_WIDGET_LAYOUT_HORIZONTAL 1
#define CONTAINER_WIDGET_LAYOUT_VERTICAL 2

struct ContainerWidget : public Widget {
	ListOfAssetsPtr<Widget> widgets;
	uint16_t flags;
	int16_t overlay;
    uint16_t layout;
    uint16_t reserved1;
};

struct ContainerWidgetState : public WidgetState {
	WidgetStateFlags flags;
	int styleId;
	Overlay *overlay;
    int overlayState;
    int displayBufferIndex;
	bool displayBufferSelected;
	bool repainted;
    int offsetPrevious;

    bool updateState() override;
	void render() override;
	void enumChildren() override;
	void renderOverlayChildren();
};

} // namespace gui
} // namespace eez
