/**
 * Copyright (C) 2014 The Motel On Jupiter
 */
#ifndef MOJGAMELIB_AUXILIARY_COROUTINEAUX_H_
#define MOJGAMELIB_AUXILIARY_COROUTINEAUX_H_

#include "mojgame/includer/coroutine_include.h"

#define ccrAsContParam(var) struct ccrContextTag **ccrParam = (struct ccrContextTag **) &(var)

#define ccrBegin_(x)        if(!x) {x= *ccrParam=(struct ccrContextTag *)malloc(sizeof(*x)); x->ccrLine=0;}\
                            if (x) switch(x->ccrLine) { case 0:;

#endif /* MOJGAMELIB_AUXILIARY_COROUTINEAUX_H_ */
