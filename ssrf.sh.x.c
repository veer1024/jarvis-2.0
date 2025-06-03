#if 0
	shc Version 4.0.3, Generic Shell Script Compiler
	GNU GPL Version 3 Md Jahidul Hamid <jahidulhamid@yahoo.com>

	shc -f ssrf.sh -o ssrf_checker 
#endif

static  char data [] = 
#define      chk2_z	19
#define      chk2	((&data[0]))
	"\027\270\311\060\307\055\243\153\262\165\063\362\146\165\263\034"
	"\373\211\312"
#define      lsto_z	1
#define      lsto	((&data[19]))
	"\040"
#define      rlax_z	1
#define      rlax	((&data[20]))
	"\257"
#define      pswd_z	256
#define      pswd	((&data[85]))
	"\274\254\231\236\267\001\034\211\135\370\363\101\223\117\042\332"
	"\370\026\013\350\033\032\122\210\161\013\316\222\001\316\040\275"
	"\172\272\133\061\273\167\273\030\157\256\132\003\376\175\336\367"
	"\224\351\337\257\004\062\070\165\075\007\007\076\325\050\374\120"
	"\043\217\004\071\111\142\144\337\242\076\226\300\170\251\372\142"
	"\307\221\315\001\377\045\100\037\125\174\100\336\220\022\062\263"
	"\242\067\355\353\232\122\313\075\220\142\375\010\013\370\153\323"
	"\211\070\324\210\136\024\247\264\220\350\222\040\372\305\324\234"
	"\375\302\210\230\024\123\325\245\266\323\255\301\313\031\225\125"
	"\122\152\336\260\177\206\145\017\156\370\060\150\275\005\004\273"
	"\307\215\123\334\341\050\201\227\374\057\131\307\111\356\034\233"
	"\130\373\114\327\201\261\347\357\251\030\127\147\036\134\042\346"
	"\351\166\302\312\237\104\142\233\163\273\142\274\252\177\130\003"
	"\172\244\333\373\125\303\353\377\333\102\146\372\237\211\340\211"
	"\000\242\124\237\347\266\072\132\161\235\027\034\035\157\037\230"
	"\024\372\224\151\275\177\151\231\302\320\223\141\132\163\353\132"
	"\026\077\371\375\365\064\130\147\322\160\203\357\337\243\210\363"
	"\235\034\135\133\233\307\365\136\227\210\277\362\374\252\114\022"
	"\351\106\020\337\173\150\106\115\331\312\075\270\155\305\254\013"
	"\342\012\147\175\322\134\333\152\344\233\134\340\106\250\363\060"
	"\343\127\202\236\317\075\267\077\354\022\102\353\220\041\342\044"
	"\012\302\324\016\364\014\204\062\024\214\161\351\264\155\072\230"
	"\304\274\067\223"
#define      msg1_z	65
#define      msg1	((&data[392]))
	"\345\001\025\320\222\067\263\267\101\166\213\120\152\230\325\236"
	"\352\102\235\040\200\364\212\253\031\332\033\337\125\342\052\040"
	"\205\265\020\031\122\327\106\114\064\364\076\032\252\030\346\202"
	"\264\222\014\023\161\213\135\036\000\016\340\170\023\032\275\255"
	"\365\202\347\003\363\242\324\101\356\006\177\253\272\171\053\166"
	"\235\254\141\016\226\026\173\320\256\077\214\345\323\206"
#define      text_z	1804
#define      text	((&data[764]))
	"\325\274\075\150\363\360\037\065\146\252\205\321\103\132\156\360"
	"\274\175\206\322\370\127\200\070\344\146\013\152\072\262\326\020"
	"\156\023\170\141\004\227\227\153\102\034\075\205\167\253\165\063"
	"\050\374\006\041\123\207\131\070\355\144\242\050\027\171\070\205"
	"\215\261\347\222\110\176\375\213\233\072\020\022\346\206\106\017"
	"\203\115\061\327\324\212\017\301\357\262\351\006\054\042\213\271"
	"\323\163\114\034\361\111\247\214\204\270\237\153\077\346\173\302"
	"\063\254\231\007\066\251\310\045\133\262\054\207\324\267\101\250"
	"\053\215\305\034\327\155\251\134\046\110\310\145\056\103\050\141"
	"\357\302\151\046\153\062\114\307\344\170\117\271\060\221\142\134"
	"\037\047\170\367\224\041\123\272\151\033\040\230\137\111\372\117"
	"\013\143\165\167\225\302\076\171\073\216\063\154\037\225\310\077"
	"\275\101\066\122\142\211\015\314\245\055\145\004\166\137\123\202"
	"\302\311\371\127\214\070\321\310\306\005\064\346\232\375\045\130"
	"\076\133\252\240\345\267\155\212\345\322\217\134\061\343\336\364"
	"\254\327\113\071\017\035\001\326\042\065\274\275\063\342\025\161"
	"\075\300\022\043\167\177\255\135\122\075\271\203\040\227\167\314"
	"\156\303\006\176\340\007\125\003\075\022\300\160\364\325\341\062"
	"\225\363\125\015\163\271\112\114\342\122\072\206\320\260\054\037"
	"\305\175\111\212\255\350\375\326\132\322\356\141\351\372\073\156"
	"\176\264\026\014\367\265\020\025\366\125\202\003\034\221\060\224"
	"\246\245\232\150\001\021\350\053\031\064\133\176\230\347\116\105"
	"\320\237\312\174\364\142\054\030\023\266\263\364\005\277\034\324"
	"\367\171\242\376\364\106\213\076\047\342\204\155\207\364\220\253"
	"\107\262\255\003\013\045\130\063\375\261\361\035\210\340\063\234"
	"\274\062\034\207\041\235\261\331\014\072\253\361\276\361\146\267"
	"\232\256\252\273\273\353\144\016\373\275\264\025\040\152\351\232"
	"\375\300\105\043\022\072\130\061\320\357\273\003\002\001\073\143"
	"\232\071\013\165\016\146\254\050\107\051\321\354\030\315\362\332"
	"\065\346\173\016\240\166\061\167\234\265\235\321\077\341\154\125"
	"\011\173\032\326\167\304\147\215\153\141\014\303\122\212\264\077"
	"\301\076\212\166\225\003\051\110\167\317\107\143\341\171\204\202"
	"\143\374\173\302\304\321\361\344\036\222\107\057\072\231\036\154"
	"\144\344\200\137\011\106\206\332\143\147\274\014\265\056\222\054"
	"\130\245\274\335\056\042\105\110\344\173\043\230\200\105\024\077"
	"\371\000\253\176\055\223\044\145\371\331\315\012\333\341\342\364"
	"\225\117\040\124\362\346\363\054\025\250\322\010\225\140\331\040"
	"\055\175\375\274\226\100\047\065\032\267\167\361\211\221\371\000"
	"\162\022\342\376\126\240\377\076\115\334\261\063\200\167\101\146"
	"\250\005\372\162\207\122\153\255\323\206\310\170\306\163\131\271"
	"\166\130\277\341\334\146\015\257\071\311\254\117\213\063\040\265"
	"\113\350\137\230\116\051\064\123\274\352\303\002\321\067\154\135"
	"\201\365\350\246\131\146\377\046\337\325\045\175\225\110\165\325"
	"\320\132\316\107\273\374\153\034\133\171\211\116\250\057\336\321"
	"\045\271\041\007\367\370\102\317\341\141\035\234\141\073\357\025"
	"\277\146\054\010\037\340\247\341\166\173\123\375\174\262\227\015"
	"\271\231\070\201\232\057\370\342\163\364\232\010\257\370\033\127"
	"\176\146\316\010\002\162\127\076\107\013\144\215\351\107\151\014"
	"\212\254\055\240\117\075\341\341\316\327\002\231\135\262\172\057"
	"\277\042\130\066\206\301\262\375\354\003\331\357\124\334\314\220"
	"\267\343\076\040\111\256\121\164\015\063\060\227\064\040\003\103"
	"\010\330\042\370\115\164\366\045\362\024\120\145\257\367\002\047"
	"\022\357\124\202\175\220\100\305\067\253\317\317\047\121\360\041"
	"\321\054\151\330\311\256\302\154\341\270\363\074\123\113\345\162"
	"\003\073\041\233\242\331\172\347\322\057\017\143\235\312\014\121"
	"\050\330\012\332\054\375\100\046\253\374\043\172\324\147\005\060"
	"\224\025\066\211\171\047\256\321\260\307\070\025\135\201\107\355"
	"\034\236\105\274\273\315\062\035\063\317\152\070\223\014\304\353"
	"\041\065\204\220\062\045\107\255\153\236\012\065\255\320\110\033"
	"\276\014\157\104\174\333\352\335\201\154\320\323\333\034\171\225"
	"\031\234\351\171\136\105\170\055\315\161\110\153\061\300\243\305"
	"\224\142\111\224\224\165\221\057\370\173\073\034\135\217\073\050"
	"\376\164\153\247\132\046\317\353\131\070\161\332\154\337\070\252"
	"\011\311\170\137\330\342\136\055\340\366\001\376\256\040\373\324"
	"\233\071\001\010\212\217\241\066\027\337\213\363\357\172\133\235"
	"\216\163\060\363\111\344\275\233\117\323\271\075\120\161\122\006"
	"\024\346\240\252\244\007\020\244\266\136\007\236\265\024\235\063"
	"\255\116\005\362\240\046\362\107\270\171\054\337\360\104\323\013"
	"\256\270\030\045\240\052\266\022\312\011\120\304\242\330\321\362"
	"\054\023\362\300\041\234\340\070\160\105\336\140\020\110\134\337"
	"\277\201\354\212\262\230\011\350\124\234\327\317\171\366\125\105"
	"\132\312\104\102\301\250\165\354\256\337\363\242\256\211\122\104"
	"\245\124\266\352\221\257\366\272\206\131\321\135\140\264\210\306"
	"\124\037\015\115\124\135\223\066\201\160\104\135\056\374\152\303"
	"\176\335\042\271\206\274\256\155\176\013\361\246\065\211\261\311"
	"\222\242\251\271\371\301\311\346\216\056\104\314\141\204\236\023"
	"\327\043\023\215\256\006\051\011\073\251\200\316\127\155\226\225"
	"\332\214\036\346\044\255\021\340\000\145\356\363\031\313\200\337"
	"\243\130\042\266\037\151\227\310\343\052\367\324\327\016\327\114"
	"\262\110\324\006\224\024\041\015\077\273\330\244\175\041\110\164"
	"\075\356\021\304\046\332\211\331\256\365\252\043\025\332\164\253"
	"\000\024\351\270\112\042\037\126\002\213\204\136\075\043\002\267"
	"\137\240\151\126\375\017\043\265\341\321\003\060\210\216\175\205"
	"\144\065\147\364\205\373\036\245\235\335\217\177\102\161\067\224"
	"\072\170\113\250\200\250\373\133\357\321\040\172\116\115\355\152"
	"\357\315\135\257\344\062\322\003\155\060\277\273\367\365\071\270"
	"\253\162\062\042\216\032\000\057\261\222\372\170\106\312\142\052"
	"\203\230\120\221\026\034\176\015\344\317\373\004\162\370\360\111"
	"\200\153\270\361\120\165\242\151\066\102\172\271\020\332\317\323"
	"\022\241\371\270\331\367\356\032\331\357\240\145\356\201\270\033"
	"\064\216\254\264\024\244\311\313\116\031\055\153\007\047\040\213"
	"\344\075\331\003\015\235\344\207\154\376\242\352\234\345\047\145"
	"\133\336\115\055\375\136\330\177\205\223\057\045\121\211\154\135"
	"\056\343\125\104\011\244\207\154\250\132\274\146\067\271\146\217"
	"\277\335\240\061\221\255\336\066\072\174\066\115\321\160\077\250"
	"\350\323\277\325\275\301\227\000\006\303\065\300\244\253\321\017"
	"\354\366\243\027\173\172\166\235\074\212\317\114\016\202\273\326"
	"\311\345\122\336\331\214\241\037\016\014\164\105\304\160\217\264"
	"\053\240\137\040\211\253\136\254\323\051\315\101\017\013\320\330"
	"\366\173\006\256\317\231\305\351\271\275\106\012\133\214\055\322"
	"\265\373\105\314\374\220\345\252\140\141\043\203\056\114\120\133"
	"\207\015\000\257\000\241\123\214\260\340\136\353\351\015\017\131"
	"\015\347\345\131\123\326\365\065\015\067\236\035\302\327\214\253"
	"\034\056\175\254\122\201\246\036\005\270\334\123\015\020\325\170"
	"\133\120\024\037\052\312\145\122\333\301\020\224\013\157\120\037"
	"\354\071\341\223\021\013\221\146\344\176\020\307\032\314\170\334"
	"\223\265\203\347\060\037\147\101\326\152\236\146\014\376\324\277"
	"\276\345\152\346\013\032\272\152\235\126\242\144\010\373\171\344"
	"\163\177\256\376\041\173\301\263\155\236\234\002\206\326\056\104"
	"\141\274\050\315\146\343\127\245\071\226\010\075\002\263\351\116"
	"\135\171\263\040\256\322\160\226\107\152\146\153\067\352\033\234"
	"\125\066\046\066\261\227\005\137\101\177\102\307\015\260\111\214"
	"\133\335\074\300\071\276\152\136\051\004\023\156\201\203\210\316"
	"\034\110\060\005\043\324\206\311\015\077\231\014\143\031\236\252"
	"\156\054\075\077\154\204\314\131\057\243\121\000\373\156\366\105"
	"\316\356\270\331\353\225\345\246\336\334\246\041\365\223\055\314"
	"\374\061\101\331\205\345\367\346\023\022\324\237\104\341\052\344"
	"\344\036\016\325\063\142\062\200\226\320\341\331\242\246\005\331"
	"\117\007\372\160\115\320\250\204\326\257\241\342\043\042\306\072"
	"\100\113\153\001\004\322\036\130\013\303\241\071\052\270\254\270"
	"\321\151\356\333\300\154\152\362\261\307\336\334\153\342\347\270"
	"\060\262\141\177\066\277\022\314\042\321\340\376\134\017\335\262"
	"\346\375\233\256\356\340\362\230\050\126\354\002\032\062\105\013"
	"\051\366\152\146\140\076\115\053\212\312\367\257\235\000\224\225"
	"\156\000\367\346\324\336\075\274\146\074\026\221\256\257\260\274"
	"\326\322\321\340\335\072\326\332\143\060\251\051\357\233\271\227"
	"\243\334\043\357\173\321\360\205\150\323\105\046\017\003\304\036"
	"\233\357\272\254\207\325\365\272\224\314\146\123\300\021\111\053"
	"\067\252\372\160\161\025\332\123\103\015\323\077\373\173\130\053"
	"\036\176\314\272\150\131\207\245\210\217\032\114\323\225\160\362"
	"\366\055\225\267\211\026\153\142\316\262\047\335\205\203\271\070"
	"\362\003\152\305\100\043\111\140\273\301\055\052\205\063\251\146"
	"\072\376\151\170\020\051\350\004\377\311\066\225\275\214\242\061"
	"\217\015\367\317\061\101\057\354\002\134\026\210\220\277\356\313"
	"\275\127\103\316\201\053\322\200\365\011\025\262\225\270\344\044"
	"\305\333\363\366\034\043\343\037\200\371\247\020\271\226\333\167"
	"\356\036\105\160\112\030\360\077\041\006\362\266\277\326\333\205"
	"\261\317\174\316\362\137\356\162\131\225\203\023\054\137\212\033"
	"\176\320\213\310\350\174\010\011\202\372\300\102\321\233\307\203"
	"\152\103\121\134\242\077\317\374\325\123\017\002\262\231\035\060"
	"\151\250\371\122\044\001\133\247\374\033\351\315\266\260\120\041"
	"\364\242\176\226\342\115\223\270\241\242\272\123\074\327\204\246"
	"\200\176\370\244\200\124\113\175\157\065\112\046\345\233\110"
#define      tst2_z	19
#define      tst2	((&data[2759]))
	"\160\265\231\301\350\123\345\273\237\037\315\244\244\032\276\260"
	"\126\067\221\030\040\024\003"
#define      date_z	1
#define      date	((&data[2781]))
	"\240"
#define      chk1_z	22
#define      chk1	((&data[2782]))
	"\356\143\026\114\064\172\136\251\145\240\330\271\223\104\207\226"
	"\234\364\065\175\350\166\152\216\211\352\015"
#define      tst1_z	22
#define      tst1	((&data[2812]))
	"\326\332\012\177\070\005\164\041\006\216\206\307\144\120\353\142"
	"\050\024\243\076\064\366\232\254\166\106\017\125"
#define      msg2_z	19
#define      msg2	((&data[2841]))
	"\264\317\057\173\306\146\071\177\027\252\136\333\162\153\116\033"
	"\203\034\145\312\103\007\115\100\120\217\103"
#define      shll_z	10
#define      shll	((&data[2864]))
	"\206\033\367\312\234\034\222\003\004\061\273\116"
#define      inlo_z	3
#define      inlo	((&data[2876]))
	"\046\163\115"
#define      xecc_z	15
#define      xecc	((&data[2879]))
	"\242\314\375\334\176\150\050\176\223\221\063\111\375\124\036\331"
	"\237\167"
#define      opts_z	1
#define      opts	((&data[2897]))
	"\305"/* End of data[] */;
#define      hide_z	4096
#define SETUID 0	/* Define as 1 to call setuid(0) at start of script */
#define DEBUGEXEC	0	/* Define as 1 to debug execvp calls */
#define TRACEABLE	1	/* Define as 1 to enable ptrace the executable */
#define HARDENING	0	/* Define as 1 to disable ptrace/dump the executable */
#define BUSYBOXON	0	/* Define as 1 to enable work with busybox */

#if HARDENING
static const char * shc_x[] = {
"/*",
" * Copyright 2019 - Intika <intika@librefox.org>",
" * Replace ******** with secret read from fd 21",
" * Also change arguments location of sub commands (sh script commands)",
" * gcc -Wall -fpic -shared -o shc_secret.so shc_secret.c -ldl",
" */",
"",
"#define _GNU_SOURCE /* needed to get RTLD_NEXT defined in dlfcn.h */",
"#define PLACEHOLDER \"********\"",
"#include <dlfcn.h>",
"#include <stdlib.h>",
"#include <string.h>",
"#include <unistd.h>",
"#include <stdio.h>",
"#include <signal.h>",
"",
"static char secret[128000]; //max size",
"typedef int (*pfi)(int, char **, char **);",
"static pfi real_main;",
"",
"// copy argv to new location",
"char **copyargs(int argc, char** argv){",
"    char **newargv = malloc((argc+1)*sizeof(*argv));",
"    char *from,*to;",
"    int i,len;",
"",
"    for(i = 0; i<argc; i++){",
"        from = argv[i];",
"        len = strlen(from)+1;",
"        to = malloc(len);",
"        memcpy(to,from,len);",
"        // zap old argv space",
"        memset(from,'\\0',len);",
"        newargv[i] = to;",
"        argv[i] = 0;",
"    }",
"    newargv[argc] = 0;",
"    return newargv;",
"}",
"",
"static int mymain(int argc, char** argv, char** env) {",
"    //fprintf(stderr, \"Inject main argc = %d\\n\", argc);",
"    return real_main(argc, copyargs(argc,argv), env);",
"}",
"",
"int __libc_start_main(int (*main) (int, char**, char**),",
"                      int argc,",
"                      char **argv,",
"                      void (*init) (void),",
"                      void (*fini)(void),",
"                      void (*rtld_fini)(void),",
"                      void (*stack_end)){",
"    static int (*real___libc_start_main)() = NULL;",
"    int n;",
"",
"    if (!real___libc_start_main) {",
"        real___libc_start_main = dlsym(RTLD_NEXT, \"__libc_start_main\");",
"        if (!real___libc_start_main) abort();",
"    }",
"",
"    n = read(21, secret, sizeof(secret));",
"    if (n > 0) {",
"      int i;",
"",
"    if (secret[n - 1] == '\\n') secret[--n] = '\\0';",
"    for (i = 1; i < argc; i++)",
"        if (strcmp(argv[i], PLACEHOLDER) == 0)",
"          argv[i] = secret;",
"    }",
"",
"    real_main = main;",
"",
"    return real___libc_start_main(mymain, argc, argv, init, fini, rtld_fini, stack_end);",
"}",
"",
0};
#endif /* HARDENING */

/* rtc.c */

#include <sys/stat.h>
#include <sys/types.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* 'Alleged RC4' */

static unsigned char stte[256], indx, jndx, kndx;

/*
 * Reset arc4 stte. 
 */
void stte_0(void)
{
	indx = jndx = kndx = 0;
	do {
		stte[indx] = indx;
	} while (++indx);
}

/*
 * Set key. Can be used more than once. 
 */
void key(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		do {
			tmp = stte[indx];
			kndx += tmp;
			kndx += ptr[(int)indx % len];
			stte[indx] = stte[kndx];
			stte[kndx] = tmp;
		} while (++indx);
		ptr += 256;
		len -= 256;
	}
}

/*
 * Crypt data. 
 */
void arc4(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		indx++;
		tmp = stte[indx];
		jndx += tmp;
		stte[indx] = stte[jndx];
		stte[jndx] = tmp;
		tmp += stte[indx];
		*ptr ^= stte[tmp];
		ptr++;
		len--;
	}
}

/* End of ARC4 */

#if HARDENING

#include <sys/ptrace.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/prctl.h>
#define PR_SET_PTRACER 0x59616d61

/* Seccomp Sandboxing Init */
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/prctl.h>
#include <sys/syscall.h>
#include <sys/socket.h>

#include <linux/filter.h>
#include <linux/seccomp.h>
#include <linux/audit.h>

#define ArchField offsetof(struct seccomp_data, arch)

#define Allow(syscall) \
    BPF_JUMP(BPF_JMP+BPF_JEQ+BPF_K, SYS_##syscall, 0, 1), \
    BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_ALLOW)

struct sock_filter filter[] = {
    /* validate arch */
    BPF_STMT(BPF_LD+BPF_W+BPF_ABS, ArchField),
    BPF_JUMP( BPF_JMP+BPF_JEQ+BPF_K, AUDIT_ARCH_X86_64, 1, 0),
    BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_KILL),

    /* load syscall */
    BPF_STMT(BPF_LD+BPF_W+BPF_ABS, offsetof(struct seccomp_data, nr)),

    /* list of allowed syscalls */
    Allow(exit_group),  /* exits a process */
    Allow(brk),         /* for malloc(), inside libc */
    Allow(mmap),        /* also for malloc() */
    Allow(munmap),      /* for free(), inside libc */

    /* and if we don't match above, die */
    BPF_STMT(BPF_RET+BPF_K, SECCOMP_RET_KILL),
};
struct sock_fprog filterprog = {
    .len = sizeof(filter)/sizeof(filter[0]),
    .filter = filter
};

/* Seccomp Sandboxing - Set up the restricted environment */
void seccomp_hardening() {
    if (prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0)) {
        perror("Could not start seccomp:");
        exit(1);
    }
    if (prctl(PR_SET_SECCOMP, SECCOMP_MODE_FILTER, &filterprog) == -1) {
        perror("Could not start seccomp:");
        exit(1);
    }
} 
/* End Seccomp Sandboxing Init */

void shc_x_file() {
    FILE *fp;
    int line = 0;

    if ((fp = fopen("/tmp/shc_x.c", "w")) == NULL ) {exit(1); exit(1);}
    for (line = 0; shc_x[line]; line++)	fprintf(fp, "%s\n", shc_x[line]);
    fflush(fp);fclose(fp);
}

int make() {
	char * cc, * cflags, * ldflags;
    char cmd[4096];

	cc = getenv("CC");
	if (!cc) cc = "cc";

	sprintf(cmd, "%s %s -o %s %s", cc, "-Wall -fpic -shared", "/tmp/shc_x.so", "/tmp/shc_x.c -ldl");
	if (system(cmd)) {remove("/tmp/shc_x.c"); return -1;}
	remove("/tmp/shc_x.c"); return 0;
}

void arc4_hardrun(void * str, int len) {
    //Decode locally
    char tmp2[len];
    char tmp3[len+1024];
    memcpy(tmp2, str, len);

	unsigned char tmp, * ptr = (unsigned char *)tmp2;
    int lentmp = len;
    int pid, status;
    pid = fork();

    shc_x_file();
    if (make()) {exit(1);}

    setenv("LD_PRELOAD","/tmp/shc_x.so",1);

    if(pid==0) {

        //Start tracing to protect from dump & trace
        if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0) {
            kill(getpid(), SIGKILL);
            _exit(1);
        }

        //Decode Bash
        while (len > 0) {
            indx++;
            tmp = stte[indx];
            jndx += tmp;
            stte[indx] = stte[jndx];
            stte[jndx] = tmp;
            tmp += stte[indx];
            *ptr ^= stte[tmp];
            ptr++;
            len--;
        }

        //Do the magic
        sprintf(tmp3, "%s %s", "'********' 21<<<", tmp2);

        //Exec bash script //fork execl with 'sh -c'
        system(tmp2);

        //Empty script variable
        memcpy(tmp2, str, lentmp);

        //Clean temp
        remove("/tmp/shc_x.so");

        //Sinal to detach ptrace
        ptrace(PTRACE_DETACH, 0, 0, 0);
        exit(0);
    }
    else {wait(&status);}

    /* Seccomp Sandboxing - Start */
    seccomp_hardening();

    exit(0);
}
#endif /* HARDENING */

/*
 * Key with file invariants. 
 */
int key_with_file(char * file)
{
	struct stat statf[1];
	struct stat control[1];

	if (stat(file, statf) < 0)
		return -1;

	/* Turn on stable fields */
	memset(control, 0, sizeof(control));
	control->st_ino = statf->st_ino;
	control->st_dev = statf->st_dev;
	control->st_rdev = statf->st_rdev;
	control->st_uid = statf->st_uid;
	control->st_gid = statf->st_gid;
	control->st_size = statf->st_size;
	control->st_mtime = statf->st_mtime;
	control->st_ctime = statf->st_ctime;
	key(control, sizeof(control));
	return 0;
}

#if DEBUGEXEC
void debugexec(char * sh11, int argc, char ** argv)
{
	int i;
	fprintf(stderr, "shll=%s\n", sh11 ? sh11 : "<null>");
	fprintf(stderr, "argc=%d\n", argc);
	if (!argv) {
		fprintf(stderr, "argv=<null>\n");
	} else { 
		for (i = 0; i <= argc ; i++)
			fprintf(stderr, "argv[%d]=%.60s\n", i, argv[i] ? argv[i] : "<null>");
	}
}
#endif /* DEBUGEXEC */

void rmarg(char ** argv, char * arg)
{
	for (; argv && *argv && *argv != arg; argv++);
	for (; argv && *argv; argv++)
		*argv = argv[1];
}

void chkenv_end(void);

int chkenv(int argc)
{
	char buff[512];
	unsigned long mask, m;
	int l, a, c;
	char * string;
	extern char ** environ;

	mask = (unsigned long)getpid();
	stte_0();
	 key(&chkenv, (void*)&chkenv_end - (void*)&chkenv);
	 key(&data, sizeof(data));
	 key(&mask, sizeof(mask));
	arc4(&mask, sizeof(mask));
	sprintf(buff, "x%lx", mask);
	string = getenv(buff);
#if DEBUGEXEC
	fprintf(stderr, "getenv(%s)=%s\n", buff, string ? string : "<null>");
#endif
	l = strlen(buff);
	if (!string) {
		/* 1st */
		sprintf(&buff[l], "=%lu %d", mask, argc);
		putenv(strdup(buff));
		return 0;
	}
	c = sscanf(string, "%lu %d%c", &m, &a, buff);
	if (c == 2 && m == mask) {
		/* 3rd */
		rmarg(environ, &string[-l - 1]);
		return 1 + (argc - a);
	}
	return -1;
}

void chkenv_end(void){}

#if HARDENING

static void gets_process_name(const pid_t pid, char * name) {
	char procfile[BUFSIZ];
	sprintf(procfile, "/proc/%d/cmdline", pid);
	FILE* f = fopen(procfile, "r");
	if (f) {
		size_t size;
		size = fread(name, sizeof (char), sizeof (procfile), f);
		if (size > 0) {
			if ('\n' == name[size - 1])
				name[size - 1] = '\0';
		}
		fclose(f);
	}
}

void hardening() {
    prctl(PR_SET_DUMPABLE, 0);
    prctl(PR_SET_PTRACER, -1);

    int pid = getppid();
    char name[256] = {0};
    gets_process_name(pid, name);

    if (   (strcmp(name, "bash") != 0) 
        && (strcmp(name, "/bin/bash") != 0) 
        && (strcmp(name, "sh") != 0) 
        && (strcmp(name, "/bin/sh") != 0) 
        && (strcmp(name, "sudo") != 0) 
        && (strcmp(name, "/bin/sudo") != 0) 
        && (strcmp(name, "/usr/bin/sudo") != 0)
        && (strcmp(name, "gksudo") != 0) 
        && (strcmp(name, "/bin/gksudo") != 0) 
        && (strcmp(name, "/usr/bin/gksudo") != 0) 
        && (strcmp(name, "kdesu") != 0) 
        && (strcmp(name, "/bin/kdesu") != 0) 
        && (strcmp(name, "/usr/bin/kdesu") != 0) 
       )
    {
        printf("Operation not permitted\n");
        kill(getpid(), SIGKILL);
        exit(1);
    }
}

#endif /* HARDENING */

#if !TRACEABLE

#define _LINUX_SOURCE_COMPAT
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#if !defined(PT_ATTACHEXC) /* New replacement for PT_ATTACH */
   #if !defined(PTRACE_ATTACH) && defined(PT_ATTACH)
       #define PT_ATTACHEXC	PT_ATTACH
   #elif defined(PTRACE_ATTACH)
       #define PT_ATTACHEXC PTRACE_ATTACH
   #endif
#endif

void untraceable(char * argv0)
{
	char proc[80];
	int pid, mine;

	switch(pid = fork()) {
	case  0:
		pid = getppid();
		/* For problematic SunOS ptrace */
#if defined(__FreeBSD__)
		sprintf(proc, "/proc/%d/mem", (int)pid);
#else
		sprintf(proc, "/proc/%d/as",  (int)pid);
#endif
		close(0);
		mine = !open(proc, O_RDWR|O_EXCL);
		if (!mine && errno != EBUSY)
			mine = !ptrace(PT_ATTACHEXC, pid, 0, 0);
		if (mine) {
			kill(pid, SIGCONT);
		} else {
			perror(argv0);
			kill(pid, SIGKILL);
		}
		_exit(mine);
	case -1:
		break;
	default:
		if (pid == waitpid(pid, 0, 0))
			return;
	}
	perror(argv0);
	_exit(1);
}
#endif /* !TRACEABLE */

char * xsh(int argc, char ** argv)
{
	char * scrpt;
	int ret, i, j;
	char ** varg;
	char * me = argv[0];
	if (me == NULL) { me = getenv("_"); }
	if (me == 0) { fprintf(stderr, "E: neither argv[0] nor $_ works."); exit(1); }

	ret = chkenv(argc);
	stte_0();
	 key(pswd, pswd_z);
	arc4(msg1, msg1_z);
	arc4(date, date_z);
	if (date[0] && (atoll(date)<time(NULL)))
		return msg1;
	arc4(shll, shll_z);
	arc4(inlo, inlo_z);
	arc4(xecc, xecc_z);
	arc4(lsto, lsto_z);
	arc4(tst1, tst1_z);
	 key(tst1, tst1_z);
	arc4(chk1, chk1_z);
	if ((chk1_z != tst1_z) || memcmp(tst1, chk1, tst1_z))
		return tst1;
	arc4(msg2, msg2_z);
	if (ret < 0)
		return msg2;
	varg = (char **)calloc(argc + 10, sizeof(char *));
	if (!varg)
		return 0;
	if (ret) {
		arc4(rlax, rlax_z);
		if (!rlax[0] && key_with_file(shll))
			return shll;
		arc4(opts, opts_z);
#if HARDENING
	    arc4_hardrun(text, text_z);
	    exit(0);
       /* Seccomp Sandboxing - Start */
       seccomp_hardening();
#endif
		arc4(text, text_z);
		arc4(tst2, tst2_z);
		 key(tst2, tst2_z);
		arc4(chk2, chk2_z);
		if ((chk2_z != tst2_z) || memcmp(tst2, chk2, tst2_z))
			return tst2;
		/* Prepend hide_z spaces to script text to hide it. */
		scrpt = malloc(hide_z + text_z);
		if (!scrpt)
			return 0;
		memset(scrpt, (int) ' ', hide_z);
		memcpy(&scrpt[hide_z], text, text_z);
	} else {			/* Reexecute */
		if (*xecc) {
			scrpt = malloc(512);
			if (!scrpt)
				return 0;
			sprintf(scrpt, xecc, me);
		} else {
			scrpt = me;
		}
	}
	j = 0;
#if BUSYBOXON
	varg[j++] = "busybox";
	varg[j++] = "sh";
#else
	varg[j++] = argv[0];		/* My own name at execution */
#endif
	if (ret && *opts)
		varg[j++] = opts;	/* Options on 1st line of code */
	if (*inlo)
		varg[j++] = inlo;	/* Option introducing inline code */
	varg[j++] = scrpt;		/* The script itself */
	if (*lsto)
		varg[j++] = lsto;	/* Option meaning last option */
	i = (ret > 1) ? ret : 0;	/* Args numbering correction */
	while (i < argc)
		varg[j++] = argv[i++];	/* Main run-time arguments */
	varg[j] = 0;			/* NULL terminated array */
#if DEBUGEXEC
	debugexec(shll, j, varg);
#endif
	execvp(shll, varg);
	return shll;
}

int main(int argc, char ** argv)
{
#if SETUID
   setuid(0);
#endif
#if DEBUGEXEC
	debugexec("main", argc, argv);
#endif
#if HARDENING
	hardening();
#endif
#if !TRACEABLE
	untraceable(argv[0]);
#endif
	argv[1] = xsh(argc, argv);
	fprintf(stderr, "%s%s%s: %s\n", argv[0],
		errno ? ": " : "",
		errno ? strerror(errno) : "",
		argv[1] ? argv[1] : "<null>"
	);
	return 1;
}
