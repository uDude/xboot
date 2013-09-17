---
-- The 'DisplayBmtext' class is used to display bitmap text that can
-- be placed on the screen.
-- 
-- Using fontbuilder tools and export lua font files.
-- https://github.com/andryblack/fontbuilder
-- https://github.com/andryblack/fontbuilder/downloads
-- 
-- @module DisplayBmtext
local M = Class(DisplayObject)

---
-- Creates a new object of display bitmap text.
--
-- @function [parent=#DisplayBmtext] new
-- @param font (string) The path of font file that was generated by fontbuilder.
-- @param text (optional) The content of bitmap text that will be placed on the screen.
-- @param x (optional) The x coordinate of the display bitmap text.
-- @param y (optional) The y coordinate of the display bitmap text.
-- @return #DisplayBmtext
function M:init(font, text, x, y)
	DisplayObject.init(self)

	self:setPosition(x or 0, y or 0)
	self.caches = {}

	self.font = require(font)
	self.texture = Texture.new(self.font.texture.file)
	self:setText(text)
end

---
-- Draw display image to the screen.
-- 
-- @function [parent=#DisplayBmtext] setText
-- @param self
-- @param text (string) The new content of bitmap text.
-- @return A value of 'true' or 'false'.
function M:setText(text)
	if not text then return end

	local x = 0
	self.children = {}

	for c in string.gmatch(text, "[%z\1-\127\194-\244][\128-\191]*") do
		if not self.caches[c] then
			for i, v in ipairs(self.font.chars) do
				if v.char == c then
					self.caches[c] = v
					self.caches[c].texture = self.texture:region(v.x, v.y, v.w, v.h)
				end
			end
		end

		local char = self.caches[c]
		if char then
			local img = DisplayImage:new(char.texture, self.x + char.ox + x, self.y + self.font.metrics.height - char.oy)
			self:addChild(img)
			x = x + char.width
		end
	end
end

return M
