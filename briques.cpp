#include "briques.h"

Briques::Briques(){};

void Briques::setBriques()
{
    //this->r = r;
    Briques t[this->c][this->r];
    for (size_t j = 0; j < this->r; j++)
    {
        for (size_t i = 0; i < this->c; i++)
        {
            t[j][i].r = this->r;
            t[j][i].x = i * (t[j][i].w + t[j][i].p) + t[j][i].ox;
            t[j][i].y = j * (t[j][i].h + t[j][i].p) + t[j][i].oy;
            t[j][i].status = true;
            this->b_array.push_back(t[j][i]);
        }
    }
}

void Briques::display()
{
    for (size_t i = 0; i < this->b_array.size(); i++)
    {
        cout << "x: " << this->b_array[i].x << endl;
        cout << "y: " << this->b_array[i].y << endl;
        cout << "i: " << i << endl;
        cout << "-----------------------" << endl;
    }
}

/*void briques:: setJsonBriques(JSON& json) {
    json.briques_array = this->briques_array;
}*/
