#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Song;
Song* head;
class Song {
    int id;
    string title, artist;
    bool isAvailable;
    Song* next;
public:
    Song(int ID, string t, string a) {
        id = ID;
        title = t;
        artist = a;
        isAvailable = true;
        next = head = NULL;

    }
    void addSong() {
        int id;
        string title, singer;
        cout << "\nEnter Song Details:\n";
        cout << "ID: ";
        cin >> id;
        cin.ignore();
        cout << "Title: ";
        getline(cin, title);
        cout << "Artist: ";
        getline(cin, artist);

        Song* newSong = new Song(id, title, artist);
        if (head == NULL) {
            head = newSong;
        }
        else {
            newSong->next = head;
            head = newSong;
        }
        saveToFile();
        cout << "Song added successfully!\n";
    }

    void displaySongs() {
        if (head == NULL) {
            cout << "\nNo songs in library!\n";
        }
        cout << "\nPlaylist Songs:\n";
        cout << "ID\tStatus\t\tTitle\t\tArtist\n";
        Song* temp = head;
        while (temp != NULL) {
            cout << temp->id << "\t" << (temp->isAvailable ? "Available" : "Issued") << "\t" << temp->title << "\t\t" << temp->artist << endl;
            temp = temp->next;
        }
    }

    void searchSong() {
        int searchId;
        cout << "\nEnter Song ID to search: ";
        cin >> searchId;
        if (head == NULL) {
            cout << "\nPlaylist is empty!\n";
        }
        Song* temp = head;
        while (temp != NULL) {
            if (temp->id == searchId) {
                cout << "\nSong Found!\n";
                cout << "ID: " << temp->id << endl;
                cout << "Title: " << temp->title << endl;
                cout << "Artist: " << temp->artist << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "\nSong not found!\n";
    }

    void updateSong() {
        int updateId;
        cout << "\nEnter Song ID to update: ";
        cin >> updateId;
        if (head == NULL) {
            cout << "\nPlaylist is empty!\n";
        }
        Song* temp = head;
        while (temp != NULL) {
            if (temp->id == updateId) {
                cin.ignore();
                cout << "Enter new Title: ";
                getline(cin, temp->title);
                cout << "Enter new Artist: ";
                getline(cin, temp->artist);
                saveToFile();
                cout << "\nSong updated successfully!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "\nSong not found!\n";
    }

    void deleteSong() {
        int deleteId;
        cout << "\nEnter Song ID to delete: ";
        cin >> deleteId;
        if (head == NULL) {
            cout << "\nPlaylist is empty!\n";
        }
        if (head->id == deleteId) {
            Song* temp = head;
            head = head->next;
            delete temp;
            saveToFile();
            cout << "\nSong deleted successfully!\n";
            return;
        }
        Song* temp = head;
        Song* prev = NULL;
        while (temp != NULL && temp->id != deleteId) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "\nSong not found!\n";
            return;
        }
        prev->next = temp->next;
        delete temp;
        saveToFile();
        cout << "\nSong deleted successfully!\n";
    }
    void saveToFile() {
        ofstream file("PLAYLIST.txt");
        Song* temp = head;
        while (temp != NULL) {
            file << temp->id << "\t" << temp->title << "\t" << temp->artist << "\n";
            temp = temp->next;
        }
        file.close();
    }

    void loadFromFile() {
        ifstream file("PLAYLIST.txt");
        if (!file) return;
        int id;
        string title, artist;

        while (file >> id) {
            file.ignore();
            getline(file, title);
            getline(file, artist);
            addSongFromFile(id, title, artist);
        }
        file.close();
    }
    void addSongFromFile(int id, string title, string artist) {
        Song* newSong = new Song(id, title, artist);
        newSong->next = head;
        head = newSong;
    }
    ~Song() {
        saveToFile();
    }
};
int main() {
    cout << "-----------------------------------------------------" << endl;
    cout << "         SONG PLAYLIST PROGRAM      " << endl;
    cout << endl;
    cout << "         PROJECTED BY: MAHZIL SOHAIL          " << endl;
    cout << "        ROLL NO. : SU92-BSSEM-F23-211        " << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    system("cls");

    Song sng(2, "t", "a");
    sng.loadFromFile();
    int choice;
    do {
        cout << "\n** Song Playlist Program **";
        cout << "\n1. Add Song";
        cout << "\n2. Display Songs";
        cout << "\n3. Search Song";
        cout << "\n4. Update Song";
        cout << "\n5. Delete Song";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            sng.addSong();
            break;
        case 2:
            sng.displaySongs();
            break;
        case 3:
            sng.searchSong();
            break;
        case 4:
            sng.updateSong();
            break;
        case 5:
            sng.deleteSong();
            break;
        case 6:
            cout << "\nThank you for using Song Playlist Program!\n";
            break;
        default:
            cout << "\nInvalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
