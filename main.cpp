#include <iostream>  
using namespace std;  
  
class CropRotationScheduler {  
private:  
    class Node {  
    public:  
        string crop;  
        string season;  
        string harvestTime;  
        Node* next;  
  
        Node(string c, string s, string h) {  
            crop = c;  
            season = s;  
            harvestTime = h;  
            next = NULL;  
        }  
    };  
  
    Node* head;  
  
public:  
    CropRotationScheduler() {  
        head = NULL;  
    }  
  
    void addCrop(string cropName, string seasonName, string time) {  
        Node* newNode = new Node(cropName, seasonName, time);  
  
        if (head == NULL) {  
            head = newNode;  
            newNode->next = head;  
        } else {  
            Node* temp = head;  
            while (temp->next != head) {  
                temp = temp->next;  
            }  
            temp->next = newNode;  
            newNode->next = head;  
        }  
    }  
  
    void displaySchedule() {  
        if (head == NULL) {  
            cout << "No crops scheduled.\n";  
            return;  
        }  
  
        Node* temp = head;  
        int i = 1;  
  
        cout << "\n🌾 Crop Harvest Schedule:\n";  
        do {  
            cout << "Season " << i++ << ":\n";  
            cout << "Crop: " << temp->crop << endl;  
            cout << "Season Type: " << temp->season << endl;  
            cout << "Harvest Time: " << temp->harvestTime << endl;  
            cout << "----------------------\n";  
  
            temp = temp->next;  
        } while (temp != head);  
    }  
};  
  
int main() {  
    CropRotationScheduler obj;  
    int n;  
    string crop, season, time;  
  
    cout << "Enter number of seasons: ";  
    cin >> n;  
  
    for (int i = 0; i < n; i++) {  
        cout << "\nSeason " << i + 1 << ":\n";  
  
        cout << "Enter crop name: ";  
        cin >> crop;  
  
        cout << "Enter season type (Kharif/Rabi/Summer): ";  
        cin >> season;  
  
        cout << "Enter harvest time (e.g., 90 days): ";  
        cin >> time;  
  
        obj.addCrop(crop, season, time);  
    }  
  
    obj.displaySchedule();  
  
    return 0;  
}