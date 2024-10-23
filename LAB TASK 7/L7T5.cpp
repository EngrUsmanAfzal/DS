#include <iostream>
#include <string>
using namespace std;
struct Song
{
    string title;
    Song* next;
    Song* prev;
    Song(string t) : title(t), next(nullptr), prev(nullptr) {}
};
class Playlist
{
private:
    Song* head;
    Song* tail;
public:
    Playlist() : head(nullptr), tail(nullptr) {}
    void addSong(string title)
    {
        Song* newSong = new Song(title);
        if (!head)
        {
            head = tail = newSong;
        }
        else
        {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
        cout<<"Added:"<<title<<endl;
    }
    void playForward()
    {
        Song* temp = head;
        while (temp)
        {
            cout<<temp->title<<endl;
            temp = temp->next;
        }
    }
    void playBackward()
    {
        Song* temp = tail;
        while (temp)
        {
            cout<<temp->title<<endl;
            temp = temp->prev;
        }
    }
    void deleteSong(string title)
    {
        Song* temp = head;
        while (temp && temp->title != title)
        {
            temp = temp->next;
        }
        if (!temp)
        {
            cout<<"Song not found!"<<endl;
            return;
        }
        if (temp == head)
        {
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
        }
        else if (temp == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
        cout<<"Deleted:"<<title<<endl;
    }
    ~Playlist()
    {
        while (head)
        {
            Song* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main()
{
    Playlist playlist;
    playlist.addSong("Song 1");
    playlist.addSong("Song 2");
    playlist.addSong("Song 3");
    cout<<"Playlist forward:"<<endl;
    playlist.playForward();
    cout<<"Playlist backward:"<<endl;
    playlist.playBackward();
    playlist.deleteSong("Song 2");
    cout<<"Updated playlist:"<<endl;
    playlist.playForward();
    return 0;
}