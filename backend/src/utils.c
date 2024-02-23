
#define _XOPEN_SOURCE
#define __USE_XOPEN
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include "utils.h"
#include "db_utils.h"

char db_conn_info[1024];

void db_connection_init(){
	sprintf(db_conn_info, "dbname = %s user = %s password = %s host = %s port = %s",
            getenv("POSTGRES_DB"), getenv("POSTGRES_USER"),
            getenv("POSTGRES_PASSWORD"), getenv("POSTGRES_HOST"),
            getenv("POSTGRES_PORT"));
}

db_conn_t* open_db_connection() {
    db_conn_t* conn = PQconnectdb(db_conn_info);
    return PQstatus(conn) == CONNECTION_OK ? conn : NULL;
}

void close_db_connection(db_conn_t* conn){
	PQfinish(conn);
}

void timestamp_to_string(char* str, size_t size, const timestamp_t* ts) {
	strftime(str, size, DB_TIMESTAMP_FORMAT, ts);
}

timestamp_t string_to_timestamp(const char* str) {
	timestamp_t timestamp;
	strptime(str, DB_TIMESTAMP_FORMAT, &timestamp);
	return timestamp;
}

bool timestamp_equal(const timestamp_t* ts1, const timestamp_t* ts2){
	char str1[STRING_TIMESTAMP_MAX_LENGTH];
	char str2[STRING_TIMESTAMP_MAX_LENGTH];
	timestamp_to_string(str1, STRING_TIMESTAMP_MAX_LENGTH, ts1);
	timestamp_to_string(str2, STRING_TIMESTAMP_MAX_LENGTH, ts2);
	return !strcmp(str1, str2);
}

void alloc_and_strcpy(char* *destination, const char* source)
{
	*destination = (char *)malloc(sizeof(char) * strlen(source) + 1);
	strcpy(*destination, source);
}