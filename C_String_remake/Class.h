#pragma once
class String
{
private:
    char* str;
    int length;


public:

    String()
    {
        str = nullptr;
        length = 0;
    }

    String(const String& other) : length(other.length)
    {
        if (other.str)
        {
            str = new char[length + 1];
            std::strcpy(str, other.str);
        }
        else
        {
            str = nullptr;
        }
    }

    String(const char* str)
    {

        length = strlen(str);
        this->str = new char[length + 1];

        for (int i = 0; i < length; i++)
        {
            this->str[i] = str[i];
        }

        this->str[length] = '\0';

    }

    ~String()
    {
        delete[] this->str;
    }

    String& operator =(const String& other)
    {
        if (this->str != nullptr)
        {
            delete[] str;
        }

        length = strlen(other.str);
        this->str = new char[length + 1];

        for (int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }

        this->str[length] = '\0';

        return *this;
    }

    String operator+(const String& other)
    {

        String new_str;

        int thisLength = strlen(this->str);
        int otherLength = strlen(other.str);

        new_str.length = thisLength + otherLength;

        new_str.str = new char[thisLength + otherLength + 1];

        int i = 0;
        for (; i < thisLength; i++)
        {
            new_str.str[i] = this->str[i];
        }

        for (int j = 0; j < otherLength; j++, i++)
        {
            new_str.str[i] = other.str[j];
        }

        new_str.str[thisLength + otherLength] = '\0';

        return new_str;
    }

    void Print()
    {
        std::cout << str;
    }

    int Length()
    {
        return length;
    }

    bool operator ==(const String& other)
    {
        if (this->length != other.length)
        {
            return false;
        }

        for (int i = 0; i < this->length; i++)
        {
            if (this->str[i] != other.str[i])
            {
                return false;
            }
        }
        return true;
    }

    char& operator [](int index)
    {
        if (index < 0 || index >= length)
        {
            throw std::out_of_range("index out of bounds");
        }
        return this->str[index];
    }

    int& operator ()(char symb)
    {
        int len = strlen(this->str);
        int wrong_ind = -1;

        for (int i = 0; i <= len; i++)
        {
            if (this->str[i] == symb)
            {
                return i;
            }
        }
        return wrong_ind;
    }

    const int ToInt()
    {
        int len = strlen(this->str);
        std::cout << len;
        return len;
    }

    String(String&& other)
    {
        this->length = other.length;
        this->str = other.str;
        other.str = nullptr;
    }

    void DeleteChar(char c)
    {
        int index_c = -1;
        int len = strlen(this->str);

        for (int i = 0; i < len; i++)
        {
            if (this->str[i] == c)
            {
                index_c = i;
                break;
            }
        }

        if (index_c == -1)
        {
            Print();
            return;
        }

        char* newStr = new char[len];
        int j = 0;

        for (int i = 0; i < len; i++)
        {
            if (i != index_c)
            {
                newStr[j++] = this->str[i];
            }
        }

        newStr[j] = '\0';
        delete[] this->str;
        this->str = newStr;
        this->length = strlen(newStr);

        Print();
    }
};