module dwmstb::os;
import libc;

faultdef CANT_OPEN_PIPE;

const CInt STDIN = 0;
const CInt STDOUT = 1;
const CInt STDERR = 2;

extern fn CInt sleep(CInt sec);
extern fn CInt execvp(ZString file, ZString[] argv);
extern fn CInt dup(CInt oldfd);
extern fn CInt dup2(CInt oldfd, CInt newfd);
extern fn CInt fork();
extern fn CInt pipe(CInt[2]* fds);
extern fn void exit(CInt ret);
extern fn CFile* popen(ZString cmd, ZString mode);
extern fn CInt pclose(CFile*);


