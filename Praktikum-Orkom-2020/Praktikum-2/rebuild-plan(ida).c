/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

void *init_proc();
// void __usercall sub_8C0(int a1@<ebx>);
// ssize_t read(int fd, void *buf, size_t nbytes);
// int fflush(FILE *stream);
// char *fgets(char *s, int n, FILE *stream);
// __sighandler_t signal(int sig, __sighandler_t handler);
// unsigned int sleep(unsigned int seconds);
// unsigned int alarm(unsigned int seconds);
// char *strcpy(char *dest, const char *src);
// char *getenv(const char *name);
// int puts(const char *s);
// int __cdecl __memmove_chk(_DWORD, _DWORD, _DWORD, _DWORD); weak
// void exit(int status);
// ssize_t write(int fd, const void *buf, size_t n);
// int __isoc99_sscanf(_DWORD, const char *, ...); weak
// FILE *fopen(const char *filename, const char *modes);
// int putchar(int c);
// int *__errno_location(void);
// int __printf_chk(_DWORD, const char *, ...); weak
// int socket(int domain, int type, int protocol);
// int __fprintf_chk(_DWORD, _DWORD, const char *, ...); weak
// struct hostent *gethostbyname(const char *name);
// int strtol(const char *nptr, char **endptr, int base);
// int connect(int fd, const struct sockaddr *addr, socklen_t len);
// int close(int fd);
// const unsigned __int16 **__ctype_b_loc(void);
// int __cdecl __sprintf_chk(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); weak
// int __cdecl __cxa_finalize(_DWORD); weak
int __gmon_start__(void); // weak
void sub_AC2();
void _x86_get_pc_thunk_bx();
// char *__usercall deregister_tm_clones@<eax>(int a1@<ebp>);
int register_tm_clones();
char *_do_global_dtors_aux();
int frame_dummy();
void _x86_get_pc_thunk_dx();
int __cdecl main(int argc, const char **argv, const char **envp);
int __cdecl Tokyo3Gate(int a1);
unsigned int __cdecl HQ(int a1);
unsigned int __cdecl Pyramid(int a1);
int __cdecl func4(int a1, int a2, int a3);
unsigned int __cdecl CommandCenter(int a1);
_BYTE *__cdecl MAGI(_BYTE *a1);
unsigned int __cdecl TerminalDogma(int a1);
int __cdecl fun7(_DWORD *a1, int a2);
unsigned int kaworu();
void __noreturn sig_handler();
void __cdecl __noreturn invalid_phase(int a1);
int __cdecl string_length(_BYTE *a1);
signed int __cdecl strings_not_equal(_BYTE *a1, _BYTE *a2);
unsigned int init_eva();
signed int __cdecl blank_line(char *a1);
char *skip();
unsigned int __cdecl send_msg(int a1);
void __noreturn bad_instruction();
int __cdecl read_six_numbers(int a1, int a2);
char *read_line();
unsigned int sector_repaired();
void __noreturn sigalrm_handler();
// signed int __usercall rio_readlineb@<eax>(int *a1@<eax>, _BYTE *a2@<edx>, unsigned int a3@<ecx>);
int __cdecl submitr(char *name, __int16, int, int, int, int, int); // idb
unsigned int __cdecl init_timeout(signed int a1);
signed int __cdecl init_driver(int a1);
int __cdecl driver_post(_BYTE *a1, int a2, int a3, int a4);
int (**_libc_csu_init())();
void term_proc();
// int _isoc99_sscanf(_DWORD, const char *, ...); weak

//-------------------------------------------------------------------------
// Data declarations

int dword_0 = 1179403647; // weak
_UNKNOWN unk_25C8; // weak
int array_3036[16] = { 2, 10, 6, 1, 12, 16, 9, 3, 4, 7, 14, 5, 11, 8, 15, 13 }; // idb
_UNKNOWN unk_2A44; // weak
_UNKNOWN unk_2C6B; // weak
int dword_2D9C = 1869771333; // weak
int (*_frame_dummy_init_array_entry[2])() = { &frame_dummy, &_do_global_dtors_aux }; // weak
int (*_do_global_dtors_aux_fini_array_entry)() = &_do_global_dtors_aux; // weak
void *_dso_handle = &_dso_handle; // weak
char userid[9] = "13519107"; // weak
void *bomb_id = (void *)0x72; // weak
int *n1 = &dword_24; // weak
void *node1 = (void *)0x3BB; // weak
char _bss_start; // weak
int num_input_strings; // weak
FILE *infile; // idb
char input_strings[80000]; // idb
// extern struct _IO_FILE *stderr;
// extern _UNKNOWN _cxa_finalize; weak
// extern struct _IO_FILE *stdin;
// extern struct _IO_FILE *stdout;
// extern _UNKNOWN ITM_deregisterTMCloneTable; weak
// extern _UNKNOWN _gmon_start__; weak


//----- (00000894) --------------------------------------------------------
void *init_proc()
{
  void *result; // eax

  result = &_gmon_start__;
  if ( &_gmon_start__ )
    result = (void *)__gmon_start__();
  return result;
}
// A88: using guessed type int __gmon_start__(void);

//----- (000008C0) --------------------------------------------------------
void __usercall sub_8C0(int a1@<ebx>)
{
  int v1; // ST00_4

  v1 = *(_DWORD *)(a1 + 4);
  JUMPOUT(__CS__, *(_DWORD *)(a1 + 8));
}

//----- (00000A90) --------------------------------------------------------
#error "A93: positive sp value has been found (funcsize=2)"

//----- (00000AC2) --------------------------------------------------------
void sub_AC2()
{
  ;
}

//----- (00000AD0) --------------------------------------------------------
void _x86_get_pc_thunk_bx()
{
  ;
}

//----- (00000AE0) --------------------------------------------------------
char *__usercall deregister_tm_clones@<eax>(int a1@<ebp>)
{
  char *result; // eax
  int v2; // [esp-4h] [ebp-4h]

  result = &_bss_start;
  if ( &_bss_start != &_bss_start )
  {
    result = (char *)&ITM_deregisterTMCloneTable;
    if ( &ITM_deregisterTMCloneTable )
    {
      v2 = a1;
      result = (char *)((int (__cdecl *)(char *))ITM_deregisterTMCloneTable)(&_bss_start);
    }
  }
  return result;
}
// AE0: could not find valid save-restore pair for ebp
// 5740: using guessed type char _bss_start;

//----- (00000B20) --------------------------------------------------------
int register_tm_clones()
{
  return 0;
}
// B20: could not find valid save-restore pair for ebp

//----- (00000B70) --------------------------------------------------------
char *_do_global_dtors_aux()
{
  char *result; // eax
  int savedregs; // [esp+4h] [ebp+0h]

  if ( !_bss_start )
  {
    if ( &_cxa_finalize )
      __cxa_finalize(_dso_handle);
    result = deregister_tm_clones((int)&savedregs);
    _bss_start = 1;
  }
  return result;
}
// A80: using guessed type int __cdecl __cxa_finalize(_DWORD);
// 5004: using guessed type void *_dso_handle;
// 5740: using guessed type char _bss_start;

//----- (00000BC0) --------------------------------------------------------
int frame_dummy()
{
  return register_tm_clones();
}

//----- (00000BC9) --------------------------------------------------------
void _x86_get_pc_thunk_dx()
{
  ;
}

//----- (00000BCD) --------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  const char **v3; // esi
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax

  v3 = argv;
  if ( argc == 1 )
  {
    infile = stdin;
  }
  else
  {
    if ( argc != 2 )
    {
      __printf_chk(1, "Usage: %s [<input_file>]\n", *argv);
      exit(8);
    }
    infile = fopen(argv[1], (const char *)&unk_25C8);
    if ( !infile )
    {
      __printf_chk(1, "%s: Error: Couldn't open %s\n", *v3, v3[1]);
      exit(8);
    }
  }
  init_eva();
  puts("Welcome Pilot, there are 6 major sectors that needs to be repaired after angel's attack. We wish you best of luck.");
  v4 = read_line();
  Tokyo3Gate((int)v4);
  sector_repaired();
  puts("The Tokyo3 Gate has been repaired. On to the next one, Pilot.");
  v5 = read_line();
  HQ((int)v5);
  sector_repaired();
  puts("The Headquarter is now fully functional. Well done, Pilot. The next section awaits.");
  v6 = read_line();
  Pyramid((int)v6);
  sector_repaired();
  puts("The Pyramid is looking sturdier than ever, Pilot. How about the next section?");
  v7 = read_line();
  CommandCenter((int)v7);
  sector_repaired();
  puts("Reparation of the Command Center is done. Start working on the next one, Pilot.");
  v8 = read_line();
  MAGI(v8);
  sector_repaired();
  puts("The MAGI looks even better than before. Can you fix the last section, Pilot?");
  v9 = read_line();
  TerminalDogma((int)v9);
  sector_repaired();
  puts("The NERV HQ is fully repaired. We expect nothing less from you, Pilot.");
  __printf_chk(1, "By the way, we heard something down Terminal Dogma, can you check down there?");
  return 0;
}
// 9F0: using guessed type int __printf_chk(_DWORD, const char *, ...);

//----- (00000D72) --------------------------------------------------------
int __cdecl Tokyo3Gate(int a1)
{
  int result; // eax

  result = strings_not_equal((_BYTE *)a1, "What am I going to do if everyone thinks I'm friends with a crazy woman?");
  if ( result )
    bad_instruction();
  return result;
}

//----- (00000DA4) --------------------------------------------------------
unsigned int __cdecl HQ(int a1)
{
  int *v1; // esi
  int v3; // [esp+Ch] [ebp-28h]
  int v4; // [esp+10h] [ebp-24h]
  char v5; // [esp+1Ch] [ebp-18h]
  unsigned int v6; // [esp+24h] [ebp-10h]

  v6 = __readgsdword(0x14u);
  read_six_numbers(a1, (int)&v3);
  if ( v3 || v4 != 1 )
    bad_instruction();
  v1 = &v3;
  do
  {
    if ( v1[2] != *v1 + v1[1] )
      bad_instruction();
    ++v1;
  }
  while ( v1 != (int *)&v5 );
  return __readgsdword(0x14u) ^ v6;
}

//----- (00000E20) --------------------------------------------------------
unsigned int __cdecl Pyramid(int a1)
{
  char v1; // al
  unsigned int result; // eax
  char v3; // [esp+Fh] [ebp-19h]
  int v4; // [esp+10h] [ebp-18h]
  int v5; // [esp+14h] [ebp-14h]
  unsigned int v6; // [esp+18h] [ebp-10h]

  v6 = __readgsdword(0x14u);
  if ( __isoc99_sscanf(a1, "%d %c %d", &v4, &v3, &v5) <= 2 )
    bad_instruction();
  switch ( v4 )
  {
    case 0:
      v1 = 115;
      if ( v5 != 650 )
        bad_instruction();
      return result;
    case 1:
      v1 = 120;
      if ( v5 != 773 )
        bad_instruction();
      return result;
    case 2:
      v1 = 115;
      if ( v5 != 851 )
        bad_instruction();
      return result;
    case 3:
      v1 = 114;
      if ( v5 != 573 )
        bad_instruction();
      return result;
    case 4:
      v1 = 111;
      if ( v5 != 954 )
        bad_instruction();
      return result;
    case 5:
      v1 = 97;
      if ( v5 != 464 )
        bad_instruction();
      return result;
    case 6:
      v1 = 121;
      if ( v5 != 583 )
        bad_instruction();
      return result;
    case 7:
      v1 = 103;
      if ( v5 != 236 )
        bad_instruction();
      return result;
    default:
      bad_instruction();
      return result;
  }
  if ( v3 != v1 )
    bad_instruction();
  return __readgsdword(0x14u) ^ v6;
}
// 9B0: using guessed type int __isoc99_sscanf(_DWORD, const char *, ...);

//----- (00000FA0) --------------------------------------------------------
int __cdecl func4(int a1, int a2, int a3)
{
  int v3; // edx
  int result; // eax

  v3 = a2 + (a3 - a2) / 2;
  if ( v3 > a1 )
    return 2 * func4(a1, a2, v3 - 1);
  result = 0;
  if ( v3 < a1 )
    result = 2 * func4(a1, v3 + 1, a3) + 1;
  return result;
}

//----- (00000FFE) --------------------------------------------------------
unsigned int __cdecl CommandCenter(int a1)
{
  unsigned int v2; // [esp+4h] [ebp-18h]
  int v3; // [esp+8h] [ebp-14h]
  unsigned int v4; // [esp+Ch] [ebp-10h]

  v4 = __readgsdword(0x14u);
  if ( __isoc99_sscanf(a1, "%d %d", &v2, &v3) != 2 || v2 > 0xE )
    bad_instruction();
  if ( func4(v2, 0, 14) != 1 || v3 != 1 )
    bad_instruction();
  return __readgsdword(0x14u) ^ v4;
}
// 9B0: using guessed type int __isoc99_sscanf(_DWORD, const char *, ...);

//----- (00001082) --------------------------------------------------------
_BYTE *__cdecl MAGI(_BYTE *a1)
{
  _BYTE *result; // eax
  int v2; // ecx

  if ( string_length(a1) != 6 )
    bad_instruction();
  result = a1;
  v2 = 0;
  do
    v2 += array_3036[*result++ & 0xF];
  while ( result != a1 + 6 );
  if ( v2 != 55 )
    bad_instruction();
  return result;
}

//----- (000010D9) --------------------------------------------------------
unsigned int __cdecl TerminalDogma(int a1)
{
  signed int v1; // ebp
  signed int v2; // esi
  void **v3; // edx
  signed int v4; // eax
  int v5; // esi
  int v6; // ecx
  int v7; // esi
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  signed int v13; // edi
  int v15[6]; // [esp+14h] [ebp-50h]
  int v16; // [esp+2Ch] [ebp-38h]
  int v17; // [esp+30h] [ebp-34h]
  int v18; // [esp+34h] [ebp-30h]
  int v19; // [esp+38h] [ebp-2Ch]
  int v20; // [esp+3Ch] [ebp-28h]
  int v21; // [esp+40h] [ebp-24h]
  unsigned int v22; // [esp+44h] [ebp-20h]

  v22 = __readgsdword(0x14u);
  read_six_numbers(a1, (int)v15);
  v1 = 0;
  while ( 1 )
  {
    if ( (unsigned int)(v15[v1] - 1) > 5 )
      bad_instruction();
    if ( ++v1 == 6 )
      break;
    v2 = v1;
    do
    {
      if ( v15[v1 - 1] == v15[v2] )
        bad_instruction();
      ++v2;
    }
    while ( v2 <= 5 );
  }
  v5 = 0;
  do
  {
    v6 = v15[v5];
    v4 = 1;
    v3 = &node1;
    if ( v6 > 1 )
    {
      do
      {
        v3 = (void **)v3[2];
        ++v4;
      }
      while ( v4 != v6 );
    }
    *(&v16 + v5++) = (int)v3;
  }
  while ( v5 != 6 );
  v7 = v16;
  v8 = v17;
  *(_DWORD *)(v16 + 8) = v17;
  v9 = v18;
  *(_DWORD *)(v8 + 8) = v18;
  v10 = v19;
  *(_DWORD *)(v9 + 8) = v19;
  v11 = v20;
  *(_DWORD *)(v10 + 8) = v20;
  v12 = v21;
  *(_DWORD *)(v11 + 8) = v21;
  *(_DWORD *)(v12 + 8) = 0;
  v13 = 5;
  do
  {
    if ( *(_DWORD *)v7 > **(_DWORD **)(v7 + 8) )
      bad_instruction();
    v7 = *(_DWORD *)(v7 + 8);
    --v13;
  }
  while ( v13 );
  return __readgsdword(0x14u) ^ v22;
}
// 54F8: using guessed type void *node1;
// 10D9: using guessed type int var_50[6];

//----- (000011E4) --------------------------------------------------------
int __cdecl fun7(_DWORD *a1, int a2)
{
  int result; // eax

  if ( !a1 )
    return -1;
  if ( *a1 > a2 )
    return 2 * fun7((_DWORD *)a1[1], a2);
  result = 0;
  if ( *a1 != a2 )
    result = 2 * fun7((_DWORD *)a1[2], a2) + 1;
  return result;
}

//----- (00001237) --------------------------------------------------------
unsigned int kaworu()
{
  char *v0; // eax
  int v1; // esi

  v0 = read_line();
  v1 = strtol(v0, 0, 10);
  if ( (unsigned int)(v1 - 1) > 0x3E8 )
    bad_instruction();
  if ( fun7(&n1, v1) != 5 )
    bad_instruction();
  puts("The fact that you have a place where you can return home, will lead you to happiness. That is a good fact");
  return sector_repaired();
}
// 54A4: using guessed type int *n1;

//----- (000012A6) --------------------------------------------------------
void __noreturn sig_handler()
{
  puts("Coward! Face your problems, Pilot. Don't run away!!!!");
  sleep(6u);
  __printf_chk(1, "Well... ");
  fflush(stdout);
  sleep(1u);
  puts("Even Pen Pen is more useful than you");
  exit(16);
}
// 9F0: using guessed type int __printf_chk(_DWORD, const char *, ...);

//----- (00001314) --------------------------------------------------------
void __cdecl __noreturn invalid_phase(int a1)
{
  __printf_chk(1, "Invalid phase%s\n");
  exit(8);
}
// 9F0: using guessed type int __printf_chk(_DWORD, const char *, ...);

//----- (00001341) --------------------------------------------------------
int __cdecl string_length(_BYTE *a1)
{
  int result; // eax

  if ( !*a1 )
    return 0;
  result = 0;
  do
    ++result;
  while ( a1[result] );
  return result;
}

//----- (00001360) --------------------------------------------------------
signed int __cdecl strings_not_equal(_BYTE *a1, _BYTE *a2)
{
  _BYTE *v2; // ebx
  _BYTE *v3; // esi
  int v4; // edi
  int v5; // eax
  signed int v6; // edx

  v2 = a1;
  v3 = a2;
  v4 = string_length(a1);
  v5 = string_length(a2);
  v6 = 1;
  if ( v4 == v5 )
  {
    if ( *a1 )
    {
      if ( *a1 == *a2 )
      {
        while ( 1 )
        {
          ++v2;
          ++v3;
          if ( !*v2 )
            break;
          if ( *v3 != *v2 )
            return 1;
        }
        v6 = 0;
      }
      else
      {
        v6 = 1;
      }
    }
    else
    {
      v6 = 0;
    }
  }
  return v6;
}

//----- (000013C5) --------------------------------------------------------
unsigned int init_eva()
{
  char v1; // [esp+1Ch] [ebp-2010h]
  unsigned int v2; // [esp+201Ch] [ebp-10h]

  v2 = __readgsdword(0x14u);
  signal(2, (__sighandler_t)sig_handler);
  if ( init_driver((int)&v1) < 0 )
  {
    __printf_chk(1, "Initialization error:\n%s\n", &v1);
    exit(8);
  }
  return __readgsdword(0x14u) ^ v2;
}
// 9F0: using guessed type int __printf_chk(_DWORD, const char *, ...);

//----- (00001449) --------------------------------------------------------
signed int __cdecl blank_line(char *a1)
{
  char *v1; // edi
  char v2; // si

  v1 = a1;
  while ( 1 )
  {
    v2 = *v1;
    if ( !*v1 )
      break;
    ++v1;
    if ( !((*__ctype_b_loc())[v2] & 0x2000) )
      return 0;
  }
  return 1;
}

//----- (0000148A) --------------------------------------------------------
char *skip()
{
  char *v0; // eax
  char *v1; // ebp

  do
  {
    v0 = fgets(&input_strings[400 * num_input_strings], 400, infile);
    v1 = v0;
  }
  while ( v0 && blank_line(v0) );
  return v1;
}
// 5744: using guessed type int num_input_strings;

//----- (000014E7) --------------------------------------------------------
unsigned int __cdecl send_msg(int a1)
{
  const char *v1; // eax
  char v3; // [esp+1Ch] [ebp-4020h]
  char s; // [esp+201Ch] [ebp-2020h]
  unsigned int v5; // [esp+401Ch] [ebp-20h]

  v5 = __readgsdword(0x14u);
  if ( strlen(&input_strings[400 * (num_input_strings - 1)]) + 100 > 0x2000 )
  {
    __printf_chk(1, "ERROR: Input string is too large.");
    exit(8);
  }
  v1 = "defused";
  if ( !a1 )
    v1 = "exploded";
  __sprintf_chk(
    &v3,
    1,
    0x2000,
    "%d:%s:%d:%s",
    bomb_id,
    v1,
    num_input_strings,
    &input_strings[400 * (num_input_strings - 1)]);
  if ( driver_post(userid, (int)&v3, 0, (int)&s) < 0 )
  {
    puts(&s);
    exit(0);
  }
  return __readgsdword(0x14u) ^ v5;
}
// 9F0: using guessed type int __printf_chk(_DWORD, const char *, ...);
// A70: using guessed type int __cdecl __sprintf_chk(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 54A0: using guessed type void *bomb_id;
// 5744: using guessed type int num_input_strings;

//----- (000015EA) --------------------------------------------------------
void __noreturn bad_instruction()
{
  puts((const char *)&unk_2A44);
  puts("As you try to get up from your eva, you hear a familiar voice screamed from across the valley,");
  putchar(46);
  fflush(stdout);
  sleep(1u);
  putchar(46);
  fflush(stdout);
  sleep(1u);
  puts(".");
  fflush(stdout);
  sleep(1u);
  puts("THIRD IMPACT!!!!");
  fflush(stdout);
  send_msg(0);
  puts("The assistants have been notified of your incompetence.");
  exit(8);
}

//----- (000016C0) --------------------------------------------------------
int __cdecl read_six_numbers(int a1, int a2)
{
  int result; // eax

  result = __isoc99_sscanf(a1, (const char *)&unk_2C6B, a2, a2 + 4, a2 + 8, a2 + 12, a2 + 16, a2 + 20);
  if ( result <= 5 )
    bad_instruction();
  return result;
}
// 9B0: using guessed type int __isoc99_sscanf(_DWORD, const char *, ...);

//----- (0000170A) --------------------------------------------------------
char *read_line()
{
  int v0; // edx
  char *v1; // esi
  unsigned int v2; // kr04_4
  int v4; // eax

  if ( !skip() )
  {
    if ( infile == stdin )
    {
      puts("Error: Premature EOF on stdin");
      exit(8);
    }
    if ( getenv("GRADE_BOMB") )
      exit(0);
    infile = stdin;
    if ( !skip() )
    {
      puts("Error: Premature EOF on stdin");
      exit(0);
    }
  }
  v0 = num_input_strings;
  v1 = &input_strings[400 * num_input_strings];
  v2 = strlen(&input_strings[400 * num_input_strings]) + 1;
  if ( (signed int)(v2 - 1) > 398 )
  {
    puts("Error: Input line too long");
    v4 = num_input_strings++;
    strcpy(&input_strings[400 * v4], "***truncated***");
    bad_instruction();
  }
  input_strings[400 * num_input_strings - 2 + v2] = 0;
  num_input_strings = v0 + 1;
  return v1;
}
// 5744: using guessed type int num_input_strings;

//----- (0000183D) --------------------------------------------------------
unsigned int sector_repaired()
{
  char v1; // [esp+14h] [ebp-1A8h]
  char v2; // [esp+18h] [ebp-1A4h]
  char v3; // [esp+1Ch] [ebp-1A0h]
  unsigned int v4; // [esp+1ACh] [ebp-10h]

  v4 = __readgsdword(0x14u);
  send_msg(1);
  if ( num_input_strings == 6 )
  {
    if ( __isoc99_sscanf(&input_strings[1200], "%d %d %s", &v1, &v2, &v3) == 3
      && !strings_not_equal(&v3, "GodisinHeavenAllisRightwithTheWorld") )
    {
      puts("You found Kaworu down near Terminal Dogma.");
      puts("Can you terminate him, Pilot?");
      kaworu();
    }
    puts("Your assistants have been notified.");
    puts("Make sure to submit your answers on answers.txt");
    puts("and C codes based on your sectors.");
  }
  return __readgsdword(0x14u) ^ v4;
}
// 9B0: using guessed type int __isoc99_sscanf(_DWORD, const char *, ...);
// 5744: using guessed type int num_input_strings;

//----- (00001937) --------------------------------------------------------
void __noreturn sigalrm_handler()
{
  __fprintf_chk(stderr, 1, "Program timed out after %d seconds\n", 0);
  exit(1);
}
// A10: using guessed type int __fprintf_chk(_DWORD, _DWORD, const char *, ...);

//----- (0000196A) --------------------------------------------------------
signed int __usercall rio_readlineb@<eax>(int *a1@<eax>, _BYTE *a2@<edx>, unsigned int a3@<ecx>)
{
  _BYTE *v3; // ebp
  int *v4; // esi
  int *i; // edi
  int v6; // eax
  ssize_t v7; // eax
  char *v8; // ecx
  char v9; // dl
  signed int v11; // eax
  signed int v12; // [esp+8h] [ebp-24h]
  _BYTE *v13; // [esp+Ch] [ebp-20h]

  v3 = a2;
  if ( a3 <= 1 )
  {
    v12 = 1;
  }
  else
  {
    v4 = a1;
    v13 = &a2[a3 - 1];
    v12 = 1;
    for ( i = a1 + 3; ; v4[2] = (int)i )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v6 = v4[1];
          if ( v6 <= 0 )
            break;
          v8 = (char *)v4[2];
          v9 = *v8;
          v4[2] = (int)(v8 + 1);
          v4[1] = v6 - 1;
          *(++v3 - 1) = v9;
          if ( v9 != 10 )
          {
            ++v12;
            if ( v3 != v13 )
              continue;
          }
          goto LABEL_10;
        }
        v7 = read(*v4, v4 + 3, 0x2000u);
        v4[1] = v7;
        if ( v7 >= 0 )
          break;
        if ( *__errno_location() != 4 )
        {
          v11 = -1;
          goto LABEL_15;
        }
      }
      if ( !v7 )
        break;
    }
    v11 = 0;
LABEL_15:
    if ( v11 )
      return -1;
    if ( v12 == 1 )
      return 0;
  }
LABEL_10:
  *v3 = 0;
  return v12;
}

//----- (00001A3F) --------------------------------------------------------
int __cdecl submitr(char *name, __int16 a2, int a3, int a4, int a5, int a6, int a7)
{
  unsigned __int8 *v7; // esi
  struct hostent *v8; // eax
  signed int v9; // ecx
  _BYTE *v10; // edi
  signed int v11; // ebp
  signed int v12; // ecx
  _BYTE *v13; // edi
  unsigned int v14; // kr04_4
  char *v15; // ebp
  int result; // eax
  unsigned __int8 v17; // dl
  char v18; // al
  char *v19; // ebp
  size_t v20; // esi
  ssize_t v21; // eax
  bool v22; // cf
  bool v23; // zf
  signed int v24; // ecx
  char *v25; // esi
  const char *v26; // edi
  signed int v27; // eax
  _BYTE *v28; // esi
  bool v29; // cf
  bool v30; // zf
  signed int v31; // ecx
  const char *v32; // edi
  unsigned int v33; // kr08_4
  int v34; // [esp-8h] [ebp-A078h]
  int v35; // [esp-4h] [ebp-A074h]
  int v36; // [esp-4h] [ebp-A074h]
  int v37; // [esp+0h] [ebp-A070h]
  int v38; // [esp+0h] [ebp-A070h]
  unsigned int v39; // [esp+10h] [ebp-A060h]
  int v40; // [esp+10h] [ebp-A060h]
  int fd; // [esp+14h] [ebp-A05Ch]
  unsigned int v42; // [esp+20h] [ebp-A050h]
  unsigned int v43; // [esp+30h] [ebp-A040h]
  struct sockaddr addr; // [esp+34h] [ebp-A03Ch]
  int v45; // [esp+44h] [ebp-A02Ch]
  int v46; // [esp+48h] [ebp-A028h]
  char *v47; // [esp+4Ch] [ebp-A024h]
  char v48; // [esp+50h] [ebp-A020h]
  char src; // [esp+2050h] [ebp-8020h]
  char v50; // [esp+4050h] [ebp-6020h]
  char v51; // [esp+6050h] [ebp-4020h]
  char v52; // [esp+8050h] [ebp-2020h]
  char v53; // [esp+8051h] [ebp-201Fh]
  char v54; // [esp+8052h] [ebp-201Eh]
  unsigned int v55; // [esp+A050h] [ebp-20h]

  v7 = (unsigned __int8 *)a6;
  v55 = __readgsdword(0x14u);
  v43 = 0;
  fd = socket(2, 1, 0);
  if ( fd < 0 )
  {
    *(_DWORD *)a7 = 1869771333;
    *(_DWORD *)(a7 + 4) = 1126185586;
    *(_DWORD *)(a7 + 8) = 1852139884;
    *(_DWORD *)(a7 + 12) = 1853169780;
    *(_DWORD *)(a7 + 16) = 1701601889;
    *(_DWORD *)(a7 + 20) = 544175136;
    *(_DWORD *)(a7 + 24) = 1634038371;
    *(_DWORD *)(a7 + 28) = 1931502964;
    *(_DWORD *)(a7 + 32) = 1701536623;
    *(_WORD *)(a7 + 36) = 116;
    return -1;
  }
  v8 = gethostbyname(name);
  if ( !v8 )
  {
    *(_DWORD *)a7 = 1869771333;
    *(_DWORD *)(a7 + 4) = 1142962802;
    *(_DWORD *)(a7 + 8) = 1763726158;
    *(_DWORD *)(a7 + 12) = 1853169779;
    *(_DWORD *)(a7 + 16) = 1701601889;
    *(_DWORD *)(a7 + 20) = 544175136;
    *(_DWORD *)(a7 + 24) = 1869833586;
    *(_DWORD *)(a7 + 28) = 543520364;
    *(_DWORD *)(a7 + 32) = 1987208563;
    *(_DWORD *)(a7 + 36) = 1629516389;
    *(_DWORD *)(a7 + 40) = 1701995620;
    *(_WORD *)(a7 + 44) = 29555;
    *(_BYTE *)(a7 + 46) = 0;
    close(fd);
    return -1;
  }
  *(_DWORD *)addr.sa_data = 0;
  *(_DWORD *)&addr.sa_data[4] = 0;
  *(_DWORD *)&addr.sa_data[8] = 0;
  *(_WORD *)&addr.sa_data[12] = 0;
  addr.sa_family = 2;
  __memmove_chk(&addr.sa_data[2], *v8->h_addr_list, v8->h_length, 12);
  *(_WORD *)addr.sa_data = __ROR2__(a2, 8);
  if ( connect(fd, &addr, 0x10u) < 0 )
  {
    *(_DWORD *)a7 = 1869771333;
    *(_DWORD *)(a7 + 4) = 1428175474;
    *(_DWORD *)(a7 + 8) = 1818386798;
    *(_DWORD *)(a7 + 12) = 1869881445;
    *(_DWORD *)(a7 + 16) = 1852793632;
    *(_DWORD *)(a7 + 20) = 1952671086;
    *(_DWORD *)(a7 + 24) = 544175136;
    *(_DWORD *)(a7 + 28) = 543516788;
    *(_DWORD *)(a7 + 32) = 1987208563;
    *(_WORD *)(a7 + 36) = 29285;
    *(_BYTE *)(a7 + 38) = 0;
    close(fd);
    return -1;
  }
  v42 = strlen((const char *)a6) + 1;
  v9 = -1;
  v10 = (_BYTE *)a3;
  do
  {
    if ( !v9 )
      break;
    v23 = *v10++ == 0;
    --v9;
  }
  while ( !v23 );
  v11 = v9;
  v39 = strlen((const char *)a4) + 1;
  v12 = -1;
  v13 = (_BYTE *)a5;
  do
  {
    if ( !v12 )
      break;
    v23 = *v13++ == 0;
    --v12;
  }
  while ( !v23 );
  if ( v39 - v11 - v12 + 3 * v42 - 3 + 123 > 0x2000 )
  {
    *(_DWORD *)a7 = 1869771333;
    *(_DWORD *)(a7 + 4) = 1377843826;
    *(_DWORD *)(a7 + 8) = 1819636581;
    *(_DWORD *)(a7 + 12) = 1953702004;
    *(_DWORD *)(a7 + 16) = 1735289202;
    *(_DWORD *)(a7 + 20) = 1869575200;
    *(_DWORD *)(a7 + 24) = 1918987296;
    *(_DWORD *)(a7 + 28) = 539911527;
    *(_DWORD *)(a7 + 32) = 1919118921;
    *(_DWORD *)(a7 + 36) = 1702060389;
    *(_DWORD *)(a7 + 40) = 1112888096;
    *(_DWORD *)(a7 + 44) = 1381255501;
    *(_DWORD *)(a7 + 48) = 1480674655;
    *(_DWORD *)(a7 + 52) = 4609346;
    close(fd);
    return -1;
  }
  memset(&v50, 0, 0x2000u);
  v14 = strlen((const char *)a6) + 1;
  v40 = v14 - 1;
  if ( v14 != 1 )
  {
    v15 = &v50;
    do
    {
      v17 = *v7;
      v18 = 1;
      if ( (unsigned __int8)(*v7 - 42) <= 0xFu )
        v18 = ((0xFFD9u >> (*v7 - 42)) ^ 1) & 1;
      if ( v18 && v17 != 95 && (unsigned __int8)((v17 & 0xDF) - 65) > 0x19u )
      {
        if ( v17 == 32 )
        {
          *v15++ = 43;
        }
        else
        {
          if ( (unsigned __int8)(v17 - 32) > 0x5Fu && v17 != 9 )
          {
            *(_DWORD *)a7 = 1869771333;
            *(_DWORD *)(a7 + 63) = 3043941;
            qmemcpy(
              (void *)((a7 + 4) & 0xFFFFFFFC),
              (char *)&dword_2D9C - (a7 - ((a7 + 4) & 0xFFFFFFFC)),
              4 * ((a7 - ((a7 + 4) & 0xFFFFFFFC) + 67) >> 2));
            close(fd);
            return -1;
          }
          __sprintf_chk(&v52, 1, 8, "%%%02X", v17, v34, v35, v37);
          *v15 = v52;
          v15[1] = v53;
          v15[2] = v54;
          v15 += 3;
        }
      }
      else
      {
        *v15++ = v17;
      }
      ++v7;
      --v40;
    }
    while ( v40 );
  }
  __sprintf_chk(
    &src,
    1,
    0x2000,
    "GET /api/submit?result=%s HTTP/1.0\r\nAuthorization: Bearer %s\r\n\r\n",
    &v50,
    a5,
    v35,
    v37);
  v33 = strlen(&src) + 1;
  v20 = v33 - 1;
  v19 = &src;
  if ( v33 == 1 )
  {
LABEL_34:
    v45 = fd;
    v46 = 0;
    v47 = &v48;
    if ( rio_readlineb(&v45, &src, 0x2000u) <= 0 )
    {
      *(_DWORD *)a7 = 1869771333;
      *(_DWORD *)(a7 + 4) = 1126185586;
      *(_DWORD *)(a7 + 8) = 1852139884;
      *(_DWORD *)(a7 + 12) = 1853169780;
      *(_DWORD *)(a7 + 16) = 1701601889;
      *(_DWORD *)(a7 + 20) = 544175136;
      *(_DWORD *)(a7 + 24) = 1684104562;
      *(_DWORD *)(a7 + 28) = 1919510048;
      *(_DWORD *)(a7 + 32) = 1746957427;
      *(_DWORD *)(a7 + 36) = 1701077349;
      *(_DWORD *)(a7 + 40) = 1919295602;
      *(_DWORD *)(a7 + 44) = 1931505007;
      *(_DWORD *)(a7 + 48) = 1702261349;
      *(_WORD *)(a7 + 52) = 114;
      close(fd);
      result = -1;
    }
    else
    {
      __isoc99_sscanf(&src, "%s %d %[a-zA-z ]", &v51, &v43, &v52);
      v22 = v43 < 0xC8;
      v23 = v43 == 200;
      if ( v43 == 200 )
      {
        while ( 1 )
        {
          v24 = 3;
          v25 = &src;
          v26 = "\r\n";
          do
          {
            if ( !v24 )
              break;
            v22 = (unsigned __int8)*v25 < *v26;
            v23 = *v25++ == *v26++;
            --v24;
          }
          while ( v23 );
          if ( (!v22 && !v23) == v22 )
            break;
          v27 = rio_readlineb(&v45, &src, 0x2000u);
          v22 = 0;
          v23 = v27 == 0;
          if ( v27 <= 0 )
          {
            *(_DWORD *)a7 = 1869771333;
            *(_DWORD *)(a7 + 4) = 1126185586;
            *(_DWORD *)(a7 + 8) = 1852139884;
            *(_DWORD *)(a7 + 12) = 1853169780;
            *(_DWORD *)(a7 + 16) = 1701601889;
            *(_DWORD *)(a7 + 20) = 544175136;
            *(_DWORD *)(a7 + 24) = 1684104562;
            *(_DWORD *)(a7 + 28) = 1634035744;
            *(_DWORD *)(a7 + 32) = 1936876900;
            *(_DWORD *)(a7 + 36) = 1869768224;
            *(_DWORD *)(a7 + 40) = 1702043757;
            *(_DWORD *)(a7 + 44) = 1919252082;
            *(_BYTE *)(a7 + 48) = 0;
            close(fd);
            return -1;
          }
        }
        if ( rio_readlineb(&v45, &src, 0x2000u) <= 0 )
        {
          *(_DWORD *)a7 = 1869771333;
          *(_DWORD *)(a7 + 4) = 1126185586;
          *(_DWORD *)(a7 + 8) = 1852139884;
          *(_DWORD *)(a7 + 12) = 1853169780;
          *(_DWORD *)(a7 + 16) = 1701601889;
          *(_DWORD *)(a7 + 20) = 544175136;
          *(_DWORD *)(a7 + 24) = 1684104562;
          *(_DWORD *)(a7 + 28) = 1635021600;
          *(_DWORD *)(a7 + 32) = 544437620;
          *(_DWORD *)(a7 + 36) = 1936942445;
          *(_DWORD *)(a7 + 40) = 543516513;
          *(_DWORD *)(a7 + 44) = 1836020326;
          *(_DWORD *)(a7 + 48) = 1919251232;
          *(_DWORD *)(a7 + 52) = 7497078;
          close(fd);
          result = -1;
        }
        else
        {
          v28 = (_BYTE *)a7;
          strcpy((char *)a7, &src);
          close(fd);
          v31 = 3;
          v32 = "OK";
          do
          {
            if ( !v31 )
              break;
            v29 = *v28 < (const unsigned __int8)*v32;
            v30 = *v28++ == *v32++;
            --v31;
          }
          while ( v30 );
          result = -((!v29 && !v30) != v29);
        }
      }
      else
      {
        __sprintf_chk(a7, 1, -1, "Error: HTTP request failed with error %d: %s", v43, &v52, v36, v38);
        close(fd);
        result = -1;
      }
    }
  }
  else
  {
    do
    {
      v21 = write(fd, v19, v20);
      if ( v21 <= 0 )
      {
        if ( *__errno_location() != 4 )
          goto LABEL_42;
        v21 = 0;
      }
      v19 += v21;
      v20 -= v21;
    }
    while ( v20 );
    if ( (signed int)(v33 - 1) >= 0 )
      goto LABEL_34;
LABEL_42:
    *(_DWORD *)a7 = 1869771333;
    *(_DWORD *)(a7 + 4) = 1126185586;
    *(_DWORD *)(a7 + 8) = 1852139884;
    *(_DWORD *)(a7 + 12) = 1853169780;
    *(_DWORD *)(a7 + 16) = 1701601889;
    *(_DWORD *)(a7 + 20) = 544175136;
    *(_DWORD *)(a7 + 24) = 1953067639;
    *(_DWORD *)(a7 + 28) = 1869881445;
    *(_DWORD *)(a7 + 32) = 1701344288;
    *(_DWORD *)(a7 + 36) = 1919251232;
    *(_DWORD *)(a7 + 40) = 7497078;
    close(fd);
    result = -1;
  }
  return result;
}
// 970: using guessed type int __cdecl __memmove_chk(_DWORD, _DWORD, _DWORD, _DWORD);
// 9B0: using guessed type int __isoc99_sscanf(_DWORD, const char *, ...);
// A70: using guessed type int __cdecl __sprintf_chk(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 2D9C: using guessed type int dword_2D9C;

//----- (00002242) --------------------------------------------------------
unsigned int __cdecl init_timeout(signed int a1)
{
  unsigned int seconds; // esi
  unsigned int result; // eax

  seconds = a1;
  if ( a1 )
  {
    signal(14, (__sighandler_t)sigalrm_handler);
    if ( a1 < 0 )
      seconds = 0;
    result = alarm(seconds);
  }
  return result;
}

//----- (00002286) --------------------------------------------------------
signed int __cdecl init_driver(int a1)
{
  int v1; // eax
  int v2; // esi
  struct hostent *v3; // eax
  signed int result; // eax
  int v5; // [esp-4h] [ebp-48h]
  int v6; // [esp+0h] [ebp-44h]
  int v7; // [esp+4h] [ebp-40h]
  struct sockaddr addr; // [esp+14h] [ebp-30h]
  unsigned int v9; // [esp+24h] [ebp-20h]

  v9 = __readgsdword(0x14u);
  signal(13, (__sighandler_t)((char *)&dword_0 + 1));
  signal(29, (__sighandler_t)((char *)&dword_0 + 1));
  signal(29, (__sighandler_t)((char *)&dword_0 + 1));
  v1 = socket(2, 1, 0);
  if ( v1 < 0 )
  {
    *(_DWORD *)a1 = 1869771333;
    *(_DWORD *)(a1 + 4) = 1126185586;
    *(_DWORD *)(a1 + 8) = 1852139884;
    *(_DWORD *)(a1 + 12) = 1853169780;
    *(_DWORD *)(a1 + 16) = 1701601889;
    *(_DWORD *)(a1 + 20) = 544175136;
    *(_DWORD *)(a1 + 24) = 1634038371;
    *(_DWORD *)(a1 + 28) = 1931502964;
    *(_DWORD *)(a1 + 32) = 1701536623;
    *(_WORD *)(a1 + 36) = 116;
    result = -1;
  }
  else
  {
    v2 = v1;
    v3 = gethostbyname("13.76.227.33");
    if ( v3 )
    {
      *(_DWORD *)addr.sa_data = 0;
      *(_DWORD *)&addr.sa_data[4] = 0;
      *(_DWORD *)&addr.sa_data[8] = 0;
      *(_WORD *)&addr.sa_data[12] = 0;
      addr.sa_family = 2;
      __memmove_chk(&addr.sa_data[2], *v3->h_addr_list, v3->h_length, 12);
      *(_WORD *)addr.sa_data = 28219;
      if ( connect(v2, &addr, 0x10u) < 0 )
      {
        __sprintf_chk(a1, 1, -1, "Error: Unable to connect to server %s", "13.76.227.33", v5, v6, v7);
        close(v2);
        result = -1;
      }
      else
      {
        close(v2);
        *(_WORD *)a1 = 19279;
        *(_BYTE *)(a1 + 2) = 0;
        result = 0;
      }
    }
    else
    {
      *(_DWORD *)a1 = 1869771333;
      *(_DWORD *)(a1 + 4) = 1142962802;
      *(_DWORD *)(a1 + 8) = 1763726158;
      *(_DWORD *)(a1 + 12) = 1853169779;
      *(_DWORD *)(a1 + 16) = 1701601889;
      *(_DWORD *)(a1 + 20) = 544175136;
      *(_DWORD *)(a1 + 24) = 1869833586;
      *(_DWORD *)(a1 + 28) = 543520364;
      *(_DWORD *)(a1 + 32) = 1987208563;
      *(_DWORD *)(a1 + 36) = 1629516389;
      *(_DWORD *)(a1 + 40) = 1701995620;
      *(_WORD *)(a1 + 44) = 29555;
      *(_BYTE *)(a1 + 46) = 0;
      close(v2);
      result = -1;
    }
  }
  return result;
}
// 0: using guessed type int dword_0;
// 970: using guessed type int __cdecl __memmove_chk(_DWORD, _DWORD, _DWORD, _DWORD);
// A70: using guessed type int __cdecl __sprintf_chk(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (0000247A) --------------------------------------------------------
int __cdecl driver_post(_BYTE *a1, int a2, int a3, int a4)
{
  int result; // eax

  result = a3;
  if ( a3 )
  {
    __printf_chk(1, "\nAUTORESULT_STRING=%s\n", a2);
    *(_WORD *)a4 = 19279;
    *(_BYTE *)(a4 + 2) = 0;
    result = 0;
  }
  else if ( a1 && *a1 )
  {
    result = submitr("13.76.227.33", 15214, (int)"csapp", (int)a1, (int)"9068E6571D", a2, a4);
  }
  else
  {
    *(_WORD *)a4 = 19279;
    *(_BYTE *)(a4 + 2) = 0;
  }
  return result;
}
// 9F0: using guessed type int __printf_chk(_DWORD, const char *, ...);

//----- (00002510) --------------------------------------------------------
int (**_libc_csu_init())()
{
  int (**result)(); // eax
  int v1; // esi
  int v2; // edi

  init_proc();
  result = _frame_dummy_init_array_entry;
  v1 = &_do_global_dtors_aux_fini_array_entry - _frame_dummy_init_array_entry;
  if ( v1 )
  {
    v2 = 0;
    do
      result = (int (**)())_frame_dummy_init_array_entry[v2++]();
    while ( v1 != v2 );
  }
  return result;
}
// 4E60: using guessed type int (*_frame_dummy_init_array_entry[2])();
// 4E64: using guessed type int (*_do_global_dtors_aux_fini_array_entry)();

//----- (00002594) --------------------------------------------------------
void term_proc()
{
  ;
}

#error "There were 1 decompilation failure(s) on 40 function(s)"
