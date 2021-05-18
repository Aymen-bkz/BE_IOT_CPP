#include "JSON.h"


JSON:: JSON() {
}

void JSON:: set_init_json() {
    this->data = NULL;    
    Writer<StringBuffer> writer(this->data);
    //START JSON
    writer.StartObject();
    //BRIQUES JSON
    writer.Key("row");
    writer.StartArray();
    for (size_t i = 0; i < this->b_array.size(); i++)
    {
        writer.StartObject();
        writer.Key("brique_x");
        writer.Int(this->b_array[i].x);
        writer.Key("brique_y");
        writer.Int(this->b_array[i].y);
        writer.Key("brique_status");
        writer.Bool(this->b_array[i].status);
        writer.EndObject();
    }
    writer.EndArray();
    //BARRE JSON
    writer.Key("barre_x");
    writer.Int(this->barre_x);
    writer.Key("barre_y");
    writer.Int(this->barre_y);
    //BALL JSON
    writer.Key("ball_x");
    writer.Int(this->ball_x);
    writer.Key("ball_y");
    writer.Int(this->ball_y);
    writer.Key("reset");
    writer.Bool(this->reset);
    writer.Key("score");
    writer.Int(this->score);
    //BRIQUES JSON
    writer.Key("clear_brique");
    writer.Int(this->clear_brique);
    //END JSON
    writer.Key("gameover");
    writer.Bool(this->gameover);
    //END JSON
    writer.EndObject();
}

void JSON:: set_json() {
    this->data = NULL;    
    Writer<StringBuffer> writer(this->data);
    //START JSON
    writer.StartObject();
    //BARRE JSON
    writer.Key("barre_x");
    writer.Int(this->barre_x);
    writer.Key("barre_y");
    writer.Int(this->barre_y);
    //BALL JSON
    writer.Key("ball_x");
    writer.Int(this->ball_x);
    writer.Key("ball_y");
    writer.Int(this->ball_y);
    writer.Key("reset");
    writer.Bool(this->reset);
    writer.Key("score");
    writer.Int(this->score);
    //BRIQUES JSON
    writer.Key("clear_brique");
    writer.Int(this->clear_brique);
    //END JSON
    writer.Key("gameover");
    writer.Bool(this->gameover);
    writer.EndObject();
}


void JSON:: display() {
    cout << this->data.GetString() << endl;
}

vector<Briques> JSON:: operator= (vector<Briques> array) {
  for (size_t i = 0; i < array.size(); i++)
    {
        this->b_array.push_back(array[i]);
    }
}

string JSON:: get_json_data() {
  return this->data.GetString();
}
