#ifndef LIST_CREATOR_HPP
#define LIST_CREATOR_HPP

#include <string>
#include <ctime>
#include <iostream>
#include <vector>

#include <stdio.h>

using namespace std;

#define MAX_MAIL_SIZE 24
#define MIN_MAIL_SIZE 8
#define SIZEOF_ARRAY(ARR) (sizeof(ARR)/sizeof(*ARR))

static const char *server[] = {"@ggmail", "@hhotmail", "@yyahoo", "@gwwx"};
static const char *org[] = {".com", ".de", ".org", ".xyz", ".fr", ".co.uk"};

std::string random_mail (); 
vector<string> list_of_mails (int entries_count);
#endif
