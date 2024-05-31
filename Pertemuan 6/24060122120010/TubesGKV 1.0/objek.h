#ifndef OBJEK_H
#define OBJEK_H

class Objek
{
private:
    float bx;
    float by;
    float bz;
    float bsize;
    int bhitval;

public:
    //setter
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void setSize(float s);
    void setHitValue(int v);

    //getter
    float getX();
    float getY();
    float getZ();
    float getSize();
    int getHitValue(); //0 berarti tidak tembus, selain itu buat skor
};

//Batas
class Batas1: public Objek //Bangunan extends Objek
{
public:
    Batas1(float x, float y, float z, float s, float cr, float cg, float cb); //constructor
};

//Batas2
class Batas2: public Objek //Bangunan extends Objek
{
public:
    Batas2(float x, float y, float z, float s); //constructor
};

//Pohon
class Pohon: public Objek
{
public:
    Pohon(float x, float y, float z, float s);
    void pohonVersi1();
    void pohonVersi2();
    void pohonVersi3();
};

//Bom obstacle
class Bom: public Objek
{
public:
    Bom(float x, float y, float z, float s); //constructor
};

// Awan
class Awan: public Objek
{
public:
    Awan(float x, float y, float z, float s);
    void drawCloud();
};

//Portal finish
class Portal: public Objek //Bom extends Objek
{
public:
    Portal(float x, float y, float z, float s); //constructor
};

#endif 
