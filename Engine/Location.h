#pragma once


//No need to encapsulate the data as it's very basic
// so no need for private
// since the datatype is very basic, we use struct
class  Location
{
public:   
	void Add(const Location& val)
	{
		x += val.x;
		y += val.y;


	}
	bool operator==(const Location& rhs) const
	{
		return x == rhs.x && y == rhs.y; 
	}

	int x;
	int y;

};