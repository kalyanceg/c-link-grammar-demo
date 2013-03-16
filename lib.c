#include <locale.h>
#include <stdio.h>
#include "link-includes.h"
int main() {

    Dictionary    dict;
    Parse_Options opts;
    Sentence      sent;
    Linkage       linkage;
    char *        diagram;
    int           i, num_linkages;
    char *        input_string[] = {
       "John, who is a pilot, lives near my home"
};
   setlocale(LC_ALL, "");  
    opts  = parse_options_create();
    dict  = dictionary_create("4.0.dict", "4.0.knowledge", NULL, "4.0.affix");

	sent = sentence_create(input_string[0], dict);
        parse_options_set_min_null_count(opts, 0);
	num_linkages = sentence_parse(sent, opts);
	if (num_linkages > 0) {
	    linkage = linkage_create(0, sent, opts);
	    printf("%s\n", diagram = linkage_print_diagram(linkage));
            return 0;
	}
    
    printf("Incorrect Sentence");
    return 1;
}
