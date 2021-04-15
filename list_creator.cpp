#include <list_creator.hpp>


char *random_string(int size)
{
    const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
    char *str = NULL;
    if (size) 
    {   
        str = new char[size + 1];
        for (int i = 0; i < size; i++) 
        {
            str[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
        }
        str[size] = 0;
    }
    return str;
}


inline int rand_number(int max, int min)
{
    return rand()%(max-min + 1) + min;
}

string random_mail () 
{
    string mail(random_string(rand_number(MAX_MAIL_SIZE, MIN_MAIL_SIZE)));
    mail += server[rand() % SIZEOF_ARRAY(server)];
    mail += org[rand() % SIZEOF_ARRAY(org)];
    return mail;
}

vector<string> list_of_mails (int entries_count)
{
    srand(time(0));
    vector<string> mails;
    for (int i = 0; i < entries_count; i++) {
        mails.push_back(random_mail());
    }
    return mails;
}