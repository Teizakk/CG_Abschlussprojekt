#ifndef MODEL_H
#define MODEL_H

//Generelle Includes
#include <QObject>
#include <QDir>
//Debug Includes
#include <QDebug>
//Datenstrukturen Includes
#include <QVector>
#include <QVector2D>
#include <QVector3D>
//Geometrie / Vertex / Mesh Includes
#include <QOpenGLBuffer>
//externe includes
#include <modelloader.h>

class Model : public QObject {
    Q_OBJECT
private:
    //Model und Buffer-Object bezogene Daten
    QOpenGLBuffer _vbo;
    QOpenGLBuffer _ibo;
    GLfloat* _vboData;
    GLuint* _indexData;
    size_t _vboLength;
    size_t _iboLength;
    unsigned short _vertOffset;
    unsigned short _normOffset;
    unsigned short _texCoordOffset;
    size_t _stride;
    bool _hasTextureCoords;

    //Bool-Flag ob Model-Laden erfolgreich war
    bool _hasModelLoaded;

    //(ausgelagerte) Hilfsfunktionen - hauptsächlich zur Übersichtlichkeit
    void _initializeVBOs(QString const &modelFileName);
    void _fillBuffers(QString const &modelFileName);
public:
    //Konstruktor
    Model(QString const &modelFileName = "");

    //Lade Funktionen
    void loadModelFromFile(QString const &modelFileName);

    //Getter die nicht kopieren und auch Manipulation zulassen
    QOpenGLBuffer* getVBOBufferPtr();
    QOpenGLBuffer* getIBOBufferPtr();
    GLfloat* vboData();
    GLuint* indexData();

    //Einfache Getter, die nur kopieren
    size_t vboLength() const;
    size_t iboLength() const;
    unsigned short vertOffset() const;
    unsigned short normOffset() const;
    unsigned short texCoordOffset() const;
    size_t stride() const;
    bool hasTextureCoords() const;
    bool hasModelLoaded() const;

    //Debug-Print-funktionen
    void printVBOData();
    void printIBOData();
};

#endif // MODEL_H
