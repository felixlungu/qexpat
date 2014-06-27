// mac: gcc -dynamiclib -undefined dynamic_lookup -m32 -lexpat -o expat.so expat.c
// linux: gcc -shared -m32 -lexpat -o expat.so expat.c
// for 64bit use -m64

#define KXVER 3
#include <expat.h>
#include <stdio.h>
#include "k.h"

ZK stack(){R knk(2,kj(2),knk(2,ks(""),ktn(0,0)));}
ZK r0stack(K x){K r;r0(xK[0]);r=kK(xK[1])[1];kK(xK[1])[1]=kb(0);r0(xK[1]);xt=KS;r0(x);R r;}

ZV inline push(K*x,K y){if(kK(*x)[0]->j==(*x)->n)++kK(*x)[0]->j,jk(x,y);else kK(*x)[kK(*x)[0]->j++]=y;}
ZV inline pop(K*x){ kK(*x)[--kK(*x)[0]->j]=kb(0);}

ZV sh(V*stk,const XML_Char*t,const XML_Char**a){I i;J j;K st,ak,av,r=ktn(0,2);kK(r)[0]=ks((S)t);kK(r)[1]=ktn(KC,0);st=*(K*)stk;j=kK(st)[0]->j-1;
 if(*a){ak=ktn(KS,0);av=ktn(0,0);for(i=0;a[i];i+=2){js(&ak,ss((S)a[i]));jk(&av,kp((S)a[i+1]));};jk(&r,xD(ak,av));}
 if(KC==kK(kK(st)[j])[1]->t){r0(kK(kK(st)[j])[1]);kK(kK(st)[j])[1]=ktn(0,0);};jk(&kK(kK(st)[j])[1],r);push((K*)stk,r);}

ZV eh(V*stk,const XML_Char*t){pop(stk);}

ZV dh(V*stk,const XML_Char*s,I n){J j;K p,*d,st=*(K*)stk;j=kK(st)[0]->j;d=&(kK(kK(st)[j-1])[1]);if(KC!=(*d)->t)R;p=kpn((S)s,n);jv(d,p);r0(p);}

K1(xmlparse){I e=0;K r,stk=stack();XML_Parser p=XML_ParserCreate(0);
 XML_SetUserData(p,&stk);XML_SetElementHandler(p,sh,eh);XML_SetCharacterDataHandler(p,dh);
 if(KC==xt)e=XML_Parse(p,(S)xC,xn,1);else if(0==xt)DO(xn,if(KC!=xK[i]->t){e=0;break;};e=XML_Parse(p,(S)kC(xK[i]),xK[i]->n,i==xn-1));
 if(e){r=r0stack(stk);}else{r0(r0stack(stk));r=krr("xml");}XML_ParserFree(p);R r;}

