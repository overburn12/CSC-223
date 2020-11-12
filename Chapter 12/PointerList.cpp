
template <class T>
class PointerList{
private:
    T * the_list;
    int list_size;

public:
    PointerList(){
        list_size = 0;
        the_list = new T[list_size];
        for (int i = 0; i < list_size; i++)
            the_list[i] = 0;
    }

    ~PointerList(){
        delete [] the_list;
    }

    void add(T value){
        T * tmp = new T[list_size + 1];
        for (int i = 0; i < list_size; i++){
            tmp[i] = the_list[i];
        }
        list_size++;
        delete[] the_list;
        the_list = tmp;
        the_list[list_size - 1] = value;
    }

    bool is_empty(){
        return list_size == 0;
    }

    int size(){
        return list_size;
    }

    T& operator[](const int index){
        return the_list[index];
    }
};
