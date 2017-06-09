#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include "rigidbody.h"
#include <QVector>
#include <QVector3D>

class PhysicsEngine
{
public:
    PhysicsEngine();

    void addRigidBody(const RigidBody& rb);
    void simulate(const float deltaTime);

private:
    QVector<RigidBody> m_rigidBodys;
    QVector3D          m_gravity;
};

#endif // PHYSICSENGINE_H
