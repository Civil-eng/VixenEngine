/*
	Copyright (C) 2015  Matt Guerrette

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef VIX_GLCAMERA3D_H
#define VIX_GLCAMERA3D_H

#include <vix_platform.h>
#include <vix_glm.h>

namespace Vixen {

	enum class C3D_DIRECTION
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		FORWARD,
		BACKWARD
	};

	enum class C3D_TYPE
	{
		FREEFORM,
		FIRST_PERSON,
	};


	class VIX_API GLCamera3D
	{
		static const int YAW = -90;
		static const int PITCH = 0;
	public:
		GLCamera3D();

		GLCamera3D(C3D_TYPE type);

		/*Get Position*/
		const Vec3& Position() const;

		/*Get Projection Matrix*/
		const Mat4& Projection() const;

		const Vec3& Forward() const;

		/*Get View Matrix*/
		const Mat4& View() const;

		/*Set Perspective Projection*/
		void SetPerspective(float aspect, float fov, float znear, float zfar);

		/*Set View Lens*/
		void SetView(const Vec3& pos, const Vec3& target, const Vec3& up);

		/*Set Speed*/
		void SetSpeed(float speed);

		/*Set Position*/
		void SetPosition(const Vec3& pos);

		/*Get Type*/
		C3D_TYPE GetType();

		/*Set Camera Type*/
		void SetType(C3D_TYPE type);

		/*Move Camera*/
		void Move(C3D_DIRECTION cam_dir);

		/*Rotate Y*/
		void RotateY(float dt);

		/*Rotate X*/
		void RotateX(float dt);

		/*Update Camera*/
		void Update(float dt);

		float Yaw();

		float Pitch();

	private:
		Mat4	m_projection;
		Mat4	m_view;

		Vec3    m_position;
		Vec3    m_front;
		Vec3    m_up;
		Vec3    m_right;
		Vec3    m_worldUp;
		Vec3    m_moveDir;

		C3D_TYPE m_type;

		float   m_yaw;
		float   m_pitch;
		float   m_aspect;
		float   m_fov;
		float   m_znear;
		float   m_zfar;
		float   m_speed;
	};

}

#endif