
//===============================================================================================
//Questo dizionario comprende parole riguardanti l'informatica, la privacy e il sistema GNU/Linux
//===============================================================================================


//matrice di stringhe, meno personalizzabile di un vettore di vettori di stringhe ma molto piu' comoda da dichiarare
//per far riferimento a PRIVACY occorre chiamare dizionario[4][6] senza alcun operatore di risoluzione.
#ifdef LINUX
 
  #define NPAROLE 15  //Numero di parole per ogni lunghezza
  #define LPAROLE 9   //Nuero di lunghezze di parole

  char *dizionario[LPAROLE][NPAROLE]={
    {'E', 'S', 'C', 'W', 'O', 'W', 'I', 'N', 'F', 'X', 'Y', 'U', 'Y', 'N', 'G'},  //random letters of length 1
    {'SB', 'AD', 'IZ', 'MP', 'LL', 'FS', 'UG', 'EE', 'FD', 'VB', 'UT', 'EK', 'TD', 'CM', 'ML'},  //random letter of length 2
    {"GNU","TUX","LUG","MIT","GCC","GPG","APT","NSA","GIT","FSF","EFF","USB","NOX","UNI","TOR"},          
    {"ARCH","RUST","MEGA","HTML","SUDO","ROOT","SNAP","KALI","LEAK","WINE","INIT","UDOO","SENX","EINK","BASH"},   
    {"LINUS","LINUX","UNIX","PRISM","APPLE","TERES","INODE","NIXON","PUPPY","EMACS","INTEL","GNOME","ORFOX","UNITY","REDOX"}, 
    {"DISTRO","FEDORA","DEBIAN","KERNEL","PACMAN","GITHUB","OLIMEX","GENTOO","VULCAN","EDWARD","UBUNTU","BASHRC","SCRIPT","REDHAT","APACHE"},
    {"RICHARD","MRROBOT","PULPINO","ARDUINO","ASSANGE","WINDOWS","SNOWDEN","ANDROID","SAMSUNG","TEMPORA","IPHONEX","PRIVACY","KUBUNTU","XUBUNTU","LINEAGE"}, 
    {"HARDWARE","SOFTWARE","TORVALDS","PARABOLA","STALLMAN","GUARDIAN","SLAKWARE","DEBUGGER","ARPSPOOF","SPOOFING","SNIFFARE","AAAAAAAA","BBBBBBBB","CCCCCCCC","DDDDDDDD"},
    {"RASPBERRY","BACKTRACK","WIKILEAKS","CANONICAL","GNEWSENSE","ARCHLINUX","GNUICECAT","ICEWEASEL","REPLICANT","GNUSCREEN","PACCHETTO","SUPERUSER","BBBBBBBBB","CCCCCCCCC","DDDDDDDDD"}
  };
#endif 

//dizionario LINUX integrato da parole generiche
#ifdef GENERICO
 
  #define NPAROLE 20  //Numero di parole per ogni lunghezza
  #define LPAROLE 9   //Nuero di lunghezze di parole

  char *dizionario[LPAROLE][NPAROLE]={
      {'E', 'S', 'C', 'W', 'O', 'W', 'I', 'N', 'F', 'X', 'Y', 'U', 'Y', 'N', 'G', 'S', 'C', 'W', 'O', 'W'},  //random letters of length 1
      {'SB', 'AD', 'IZ', 'MP', 'LL', 'FS', 'UG', 'EE', 'FD', 'VB', 'UT', 'EK', 'TD', 'CM', 'ML', 'VB', 'UT', 'EK', 'TD', 'CM'},  //random letter of length 2
    {"GNU","TUX","LUG","MIT","GCC","GPG","APT","NSA","GIT","FSF","EFF","USB","NOX","UNI","TOR","DIE","CPU","ALU","AMD","DIR"},          
    {"ARCH","RUST","MEGA","HTML","SUDO","ROOT","SNAP","KALI","LEAK","WINE","INIT","UDOO","SENX","EINK","BASH","AMOR","OREO","NODO","NATO","CINA"},
    
    {"LINUS","LINUX","UNIX","PRISM","APPLE","TERES","INODE","NIXON","PUPPY","EMACS","INTEL","GNOME","ORFOX","UNITY","REDOX","NOTTE","ALTRO","ATOMO","SHARP","AMORE"},
    
    {"DISTRO","FEDORA","DEBIAN","KERNEL","PACMAN","GITHUB","OLIMEX","GENTOO","VULCAN","EDWARD","UBUNTU","BASHRC","SCRIPT","REDHAT","APACHE","CANADA","STRUCT","UNION","CSHARP","FLAUTO"},
    
    {"RICHARD","MRROBOT","PULPINO","ARDUINO","ASSANGE","WINDOWS","SNOWDEN","ANDROID","SAMSUNG","TEMPORA","IPHONEX","PRIVACY","KUBUNTU","XUBUNTU","LINEAGE","ITALIAN","BITWISE","TYPEDEF","GLUTINE","GNUGRUB"},
    
    {"HARDWARE","SOFTWARE","TORVALDS","PARABOLA","STALLMAN","GUARDIAN","SLAKWARE","DEBUGGER","ARPSPOOF","SPOOFING","SNIFFARE","COMPILER","RASPBIAN","TELEGRAM","INTERNET","GIGABYTE","TERABYTE","ZUCCHERO","STANDARD","HOSTNAME"},
    
    {"RASPBERRY","BACKTRACK","WIKILEAKS","CANONICAL","GNEWSENSE","ARCHLINUX","GNUICECAT","ICEWEASEL","REPLICANT","GNUSCREEN","PACCHETTO","SUPERUSER","CPLUSPLUS","INTELATOM","CAPAREZZA","ATTENTION","OBIETTIVI","ORIENTATO","FISICAUNO","BIOLOGICO"}
    
  };


#endif 
