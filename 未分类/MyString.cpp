class MyString{
private:
    char* buffer;
public:
    MyString()
    {
        buffer = new char[1];
        buffer[0] = 0;
    }

    MyString(const char* s)
    {
        buffer = new char(strlen(s) + 1);
        strcpy(buffer,s);
    }

    MyString(MyString & s)
    {
        buffer = new char (strlen(s.buffer)+1);
        strcpy(buffer,s.buffer);
    }

    ~MyString()
    {
        delete[] buffer;
    }

    MyString& operator=(const MyString &s)
    {
        dlelete[] buffer;
        buffer = new char[strlen(s.buffer)+1];
        strcpy(buffer,s.buffer);
    }
    //这个是返回引用的函数
    operator []()
    {
        
    }

};