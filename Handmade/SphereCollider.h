#ifndef SPHERE_COLLIDER_H
#define SPHERE_COLLIDER_H

/*==============================================================================================#
|                                                                                               |
| All code has been written by Karsten Vermeulen as part of the 'Handmade' game engine, for the |
| purposes of educating other fellow programmers, programming students and anyone else wishing  |
| to learn about game development, C++ and OOP. The engine, class design and overall structure  |
| is by no means perfect and there is certainly room for improvement. Feel free to use, copy,   |
| break, update and do as you wish with this code - it is there, free, for all!                 |
|																							    |
| Designed to teach. Made from scratch. Built by hand.							                |
|																							    |
#===============================================================================================#
|																								|
| If you like 'Handmade', and wish to show your support, if you have any questions about the    |
| project, or if you just want to reach out, please find me on the following channels:          |
|																						        |
| Web: http://www.karstenvermeulen.com														    |
| Facebook: https://www.facebook.com/KarstensCorner								                |
| Twitter: https://twitter.com/KarstensCorner													|
| LinkedIn: https://www.linkedin.com/in/karstenvermeulen                                        |
| GitHub: https://github.com/djkarstenv									                        |
|                                                                                               |
#===============================================================================================#
| 'Sphere' source files last updated in February 2020								            |
#==============================================================================================*/

#include "BoxCollider.h"

//TODO - Add some kind of 'central system' to render all colliders in the scene

class SphereCollider
{

public:

	SphereCollider();
	
public:

	float GetScale() const;
	float GetRadius() const;
    float GetRadiusScaled() const;
    const glm::vec3& GetPosition() const;

public:

	void SetScale(float scale);
    void SetRadius(float radius);
	void SetPosition(float x, float y, float z);

public:

	bool IsColliding(const BoxCollider& secondBox) const;
	bool IsColliding(const SphereCollider& secondSphere) const;

public:

	void Update();
	void Draw();

private:

	float m_scale;
	float m_radius;
    float m_radiusScaled;
    
    glm::vec4 m_color;
    glm::vec3 m_position;

};

#endif