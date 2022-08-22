#include <iostream>
#include <string>
#include <array>
using namespace std;
class YoutubeChannel    {
    public:
    YoutubeChannel(string name, int Subs): Name(name), Subs(Subs)   {

    }
    /*YoutubeChannel operator<<(ostream& cout) {
        cout << "Name: " << this->Name << endl;
        cout << "SSubscribers: " << this -> Subs << endl;
    }*/
    //void operator<<(ostream& , YoutubeChannel& ytstuff) {};
    string GetName();
    int GetNum();
   // YoutubeChannel operator<<(YoutubeChannel& ytstuff)  {};
   // YoutubeChannel operator==(YoutubeChannel& ytstuff)  {};
    private:
    string Name;
    int Subs;
};
string YoutubeChannel::GetName()    {
    return this ->Name;
}
int YoutubeChannel::GetNum()    {
    return this -> Subs;
}
void operator<<(ostream& cout,YoutubeChannel& ytstuff) {
        cout << "Name: " << ytstuff.GetName() << endl;
        cout << "SSubscribers: " << ytstuff.GetNum() << endl;
    };

bool operator==(YoutubeChannel& a,YoutubeChannel& b) {
    if ((a.GetName() == b.GetName()) && (a.GetNum() == b.GetNum())) {
        return true;
    }
    else{return false;}
}



int main()  {
        YoutubeChannel yt1 = YoutubeChannel("yes", 24);
        YoutubeChannel yt2 = YoutubeChannel("no", 24);
        YoutubeChannel yt3 = YoutubeChannel("lals", 25);
        cout << yt1;
        //can also call like this
        //operator<<(cout,yt1);
        cout << 5 << endl;
        cout << true << endl;
        cout << (yt1 == yt2) << endl;
        cout << (yt1.GetNum() + yt2.GetNum()) << endl;
        
}
