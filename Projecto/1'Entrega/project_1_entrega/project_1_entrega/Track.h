//
//  Track.h
//  project_1_entrega
//
//  Created by André Silva on 9/28/15.
//
//

#ifndef __project_1_entrega__Track__
#define __project_1_entrega__Track__

#include <stdio.h>

class Track{
private:
	float pos_x = -1.5;
	float pos_y = -1.5;
	float pos_z = 0.0;
public:
    Track();
    ~Track();
    void draw();
};

#endif /* defined(__project_1_entrega__Track__) */