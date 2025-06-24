/**
 * @mainpage Documentation Circular Queues
 * 
 * @section Introduction
 * Project ini merupakan project dtruktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays
 * 
 * @section Operations
 * Project ini memeiliki beberapa operasi antara lain
 * 1. Insert 
 * 2. Delete
 * 3. Display
 * 
 * @section Cara penggunaan
 * Berikut beberapa menu yang bisa digunakan
 * 1. en queue
 * 2. de queue
 * 3. display
 * 4. exit
 * 
 * @author Profil
 * - nama : Sekar Mayang
 * - nim : 20240140127
 * - kelas : C
 
 * @brief
 * @version 1.0 
 * @date 2025-06-24
 * 
 * @copyright Sekarmayang@umy.ac.id (c) 2025
 * 
 */ 

#include <iostream> 
using namespace std;
/**
 * @class Queues
 * @brief class ini untuk operasi lengkap queues
 * 
 * 
 */

class Queues
{
private:
    int FRONT; ///< variabel private front untuk menyimpan posisi dengan antrian
    int REAR; ///< variabel private rear untuk menyimpan posisi belakang antrian
    int max = 5; ///< variabel private max untuk menyimpan ukuran maximum anrtian 
    int queue_array[5]; ///< variabel private queue_aray untuk menyimpan elemen antrian

public:
/**
 * @brief construct a new queues object
 * set default quues null
 * with front = -1 and rear = -1
 */
    Queues () {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief method untuk memmasukan data dalam antrian
     * data dimasukan dalalm variabel queue_array
     */
    void insert()
    {
        int num;///< variabel num untuk menyimpan nilai
        cout << "enter a number: ";
        cin >> num;
        cout << endl;

        // 1. cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max -1)|| (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n"; //1.a
            return;                      // 1.b
        }

        //2. cek apakah antrian kosong
        if (FRONT== 1)
        {
            FRONT = 0; // 2.a
            REAR = 0;  //2.b
        }
        else
        {
            // jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max -1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }
    /** 
     * @brief method untuk menghapus dat dalam antrian
     * data dihapuskan dari dalam variabel queue_array
     */
    void remove ()
    {
        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "n\The element deleted from the queue is : " << queue_array[FRONT] << "\n";

        // cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            // jika elemen yang dihapus berada diposisi terakhir array, kembali ke awal array
            if (FRONT == max -1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;

        }
    }
    /** 
     * @brief method untuk menampilkan data dalam antrian
     * data ditampilan yang berada dalam variabel queue_array
     */

    void display ()
    {
        int FRONT_position = FRONT; ///< variabel front_posisition untuk menandakan posisi element pertama pada variabel front
        int REAR_position = REAR; ///< variabel rear_posisition untuk menandakan element terakhir pada variabel rear

    // cek apakah anrtian kosong
    if (FRONT == -1)
    {
        cout << " Queue is empty\n";
        return;
    }

    cout  << "\nElement in the queue are...\n";// 1.a

    // jika FRONT_postion <= REAR_positon, iterasi dari FRONT hingga REAR
    if (FRONT_position <= REAR_position)
    {
        while (FRONT_position <= REAR_position)
        {
            cout << queue_array [FRONT_position] <<" ";
            FRONT_position++;
        }
        cout << endl;
    }
    else
    {
        // jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
        while (FRONT_position <= max - 1)
        {
            cout << queue_array[FRONT_position] << " ";
            FRONT_position++;
        }

        FRONT_position = 0;
          while (FRONT_position <= REAR_position)
        {
            cout << queue_array [FRONT_position] <<" ";
            FRONT_position++;
        }
        cout << endl;
        }
    }
};
/** 
 * @brief method utama untuk menjalankan program
 * 
 * @return int
 */
int main ()
{
    Queues q; ///< objek untuk menggunakan member yang ada pada class queues
    char ch; ///< variabel ch untuk menyimpan pilihan pada menu yang diberikan

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete opperation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q. insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4' :
            {
                return 0;
            }
            default:
            {
                cout << "invalid opption!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "Chcek for the values enteread." << endl;
        }
    }
    return 0;
}