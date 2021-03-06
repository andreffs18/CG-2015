//
//  project_1_entrega - Track.h
//

#ifndef __TRACK_H_INCLUDED__
#define __TRACK_H_INCLUDED__

class Track : public StaticObject{
private:
    // amount of cheerios in the inner circle
    int _qtd_cheerios;
    // inner and outter radious of the track
    GLdouble _inner_circle, _outer_circle;
    
	int _qtd_oranges;
	bool _set_position = true;
	std::vector<Vector3 *> _orange_pos;
    
    // amount of butter in random places inside the track
    int _qtd_butters;
    // vector with all random butter positions and angles
    std::vector<GLdouble> _random_butter_pos_x;
    std::vector<GLdouble> _random_butter_pos_y;
    std::vector<GLdouble> _random_butter_angle;
    
    void __init__();
    void drawTrackModel();
    void drawCheerios();
    void drawButters();
	void drawOranges();
public:
    Track();
    Track(int qtd_cheerios,
          int qtd_butters, 
		  int qtd_oranges,
          GLdouble inner_circle = 0.4,
          GLdouble outer_circle = 0.8);
    ~Track();
    void draw();
};

#endif /* defined(__TRACK_H_INCLUDED__) */
