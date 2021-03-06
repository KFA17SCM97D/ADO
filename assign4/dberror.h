#ifndef DBERROR_H
#define DBERROR_H

#include "stdio.h"

/* module wide constants */
#define PAGE_SIZE 4096

/* return code definitions */
typedef int RC;

#define RC_OK 0
#define RC_FILE_NOT_FOUND 1
#define RC_FILE_HANDLE_NOT_INIT 2
#define RC_WRITE_FAILED 3
#define RC_READ_NON_EXISTING_PAGE 4
#define RC_CANNOT_FLUSH_BUFFER_POOL 5

/* requested page is out of bound */
#define RC_PAGE_OUTOFBOUND 6

/* parameters provided have null value */
#define RC_NULL_PARAM 7

/* file deletion failed */
#define RC_DELETE_FAILED 8

/* file cannot be extended */
#define RC_FILE_NOT_EXTENSIBLE 9

/* file seek or read  */
#define RC_FILE_SEEK_OR_IO_FAIL 10

/* Error shutting down buffer pool  */
#define RC_ERROR_SHUTDOWN_BUFFER_POOL 11

/* Insufficient memory for buffer pool */
#define RC_INSUFFICIENT_MEMORY 12

/* Error pinning page to buffer pool */
#define RC_ERROR_PIN_PAGE 13

/* Error un-pinning page from buffer pool */
#define RC_ERROR_UNPIN_PAGE 14

/* Error forcing page to file */
#define RC_ERROR_FORCING_PAGE 15

/* Error marking page dirty */
#define RC_ERROR_MARKING_DIRTY 16

/* Error memory allocation failed*/ 
#define RC_ERROR_MALLOC_FAILED 17 

/* Error Record not found*/
#define RC_RECORD_NOT_FOUND 18

#define RC_RM_COMPARE_VALUE_OF_DIFFERENT_DATATYPE 200
#define RC_RM_EXPR_RESULT_IS_NOT_BOOLEAN 201
#define RC_RM_BOOLEAN_EXPR_ARG_IS_NOT_BOOLEAN 202
#define RC_RM_NO_MORE_TUPLES 203
#define RC_RM_NO_PRINT_FOR_DATATYPE 204
#define RC_RM_UNKOWN_DATATYPE 205

#define RC_IM_KEY_NOT_FOUND 300
#define RC_IM_KEY_ALREADY_EXISTS 301
#define RC_IM_N_TO_LAGE 302
#define RC_IM_NO_MORE_ENTRIES 303

/* holder for error messages */
extern char *RC_message;

/* print a message to standard out describing the error */
extern void printError (RC error);
extern char *errorMessage (RC error);

// kiran
#define RC_ORDER_TOO_HIGH_FOR_PAGE 701
#define RC_INSERT_ERROR 702
#define RC_NO_RECORDS_TO_SCAN 703

#define THROW(rc,message) \
  do {			  \
    RC_message=message;	  \
    return rc;		  \
  } while (0)		  \

// check the return code and exit if it is an error
#define CHECK(code)							\
  do {									\
    int rc_internal = (code);						\
    if (rc_internal != RC_OK)						\
      {									\
	char *message = errorMessage(rc_internal);			\
	printf("[%s-L%i-%s] ERROR: Operation returned error: %s\n",__FILE__, __LINE__, __TIME__, message); \
	free(message);							\
	exit(1);							\
      }									\
  } while(0);


#endif
