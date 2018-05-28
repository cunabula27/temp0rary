#include "Button.hpp"

Button::Button()
{
}

void Button::setup(int x, int y, int z, int radius)
{
	path.setFillColor(0);
	path.setStrokeColor(255);
	path.setStrokeWidth(1);
	path.setCircleResolution(128);
	path.circle(x, y, z, radius);
}

void Button::setup(int x, int y, int z, int width, int height)
{
	path.setFillColor(0);
	path.setStrokeColor(255);
	path.setStrokeWidth(1);
	path.rectangle(x, y, z, width, height);
}

void Button::update()
{
	if (buttonOn)
	{
		path.setFillColor(70);
	}
	else 
	{
		path.setFillColor(0);
	}
}

void Button::draw()
{
	path.draw();
}