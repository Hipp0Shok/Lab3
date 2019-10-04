#include "mainwindow.h"
#include <QApplication>

template<typename T1, typename T2>
void output(HashTable<T1, T2> &existing)
{
    typename HashTable<T1, T2>::Iterator iter;
    if(existing.getLength() != 0)
    {
        iter = existing.begin();
        do
        {
            std::cout << "Key: " << *iter << " Value: " << iter.getValue() << std::endl;
        }while(iter++ != existing.end());
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    HashTable<int, int> table;
        assert(table.getLength() == 0);
        table.addPair(1, 1);
        assert(table.getLength() == 1);
        table.addPair(1, 2);
        assert((table.getLength() == 1));
        table.addPair(3, 5);
        assert(table.isPresent(1));
        assert(!table.isPresent(2));
        table.deleteKey(1);
        assert(!table.isPresent(1));
        assert(table[3] == 5);
        HashTable<int, int> table2(table);
        assert(table == table2);
        table2.addPair(26125, 15);
        assert(table2 != table);
        std::ofstream file;
        file.open("Data.txt", std::ios::out);
        file << table2;
        HashTable<int, int> table3;
        file.close();
        std::ifstream file2;
        file2.open("Data.txt", std::ios::in);
        file2 >> table3;
        assert(table3 == table2);
        table2.deleteKey(3);
        assert(table2 != table3);
        output(table3);
        table.deleteAll();
        assert(table.getLength() == 0);
        assert(table != table2);
        HashTable<std::string, float> sec;
        sec.addPair("Puten", 15.4F);
        output(sec);
        std::cout << "All is OK!" << std::endl;
    return a.exec();
}
