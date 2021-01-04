#ifndef RENDER_H
# define RENDER_H

typedef struct	s_sector
{
	PolygonList* polygons;
	ObjectList* objects;
}				t_sector;

typedef struct	s_polygon
{
	Vertex** vertices;
	int vert_number;
	//Texture* texture;
	//Sector* sector;
	//Plane plane;
}				t_polygon;

typedef struct	Object
{
	PolygonList* polies;
	ObjectList* childs;
	Matrix matrix;
};

typedef struct	Vertex
{
	Coordinate* position;
	float U, V;
};

typedef struct	Coordinate
{
	Vertex original;
	Vertex rotated;
	bool processed;
};



#endif