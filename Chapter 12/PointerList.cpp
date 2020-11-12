
template <class T>
class PointerList{
private:
    T * the_list;
    int list_size;
    int block_size;
    int num_blocks;

public:
    PointerList(){
        list_size = 0;
        num_blocks = 1;
        block_size = 10;
        the_list = new T[block_size * num_blocks];
    }

    ~PointerList(){
        delete [] the_list;
    }

    void add(T value){
        if (list_size == block_size * num_blocks)
        {
            num_blocks += 1;
            T * tmp = new T[block_size * num_blocks];
            for (int i = 0; i < list_size; i++)
            {
                tmp[i] = the_list[i];
            }
            delete[] the_list;
            the_list = tmp;
        }
        the_list[list_size] = value;
        list_size += 1;
    }

    void clear(){
        delete [] the_list;
        list_size = 0;
        num_blocks = 1;
        the_list = new T[block_size * num_blocks];
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
