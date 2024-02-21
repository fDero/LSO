#ifndef QUERIES_H
#define QUERIES_H

#include "db_utils.h"
#include "data_access.h"

#define STRING_TIMESTAMP_MAX_LENGTH 50
#define QUERY_STRING_MAX_LENGTH 1024

account_t* get_account_by_id(db_conn_t* connection, const int id);
account_t* get_account_by_email(db_conn_t* connection, const char* email);
account_array_t* get_accounts_by_book_id(db_conn_t* connection, const int id);
account_t* get_account_by_loan_id(db_conn_t* connection, const int id);
book_t* get_book_by_id(db_conn_t* connection, const int id);
book_array_t* get_books_by_account_id(db_conn_t* connection, const int id);
book_t* get_book_by_loan_id(db_conn_t* connection, const int id);
book_array_t* get_books_by_title(db_conn_t* connection, const char* title);
book_array_t* get_books_by_author(db_conn_t* connection, const char* author);
book_array_t* get_books_by_publisher(db_conn_t* connection, const char* publisher);
book_array_t* get_books_by_release_date(db_conn_t* connection, const timestamp_t* release_date);
book_array_t* get_books_by_title_and_author(db_conn_t* connection, const char* title, const char* author);
book_array_t* get_books_by_title_and_publisher(db_conn_t* connection, const char* title, const char* publisher);
book_array_t* get_books_by_title_and_release_date(db_conn_t* connection, const char* title, const timestamp_t* release_date);
book_array_t* get_books_by_author_and_publisher(db_conn_t* connection, const char* author, const char* publisher);
book_array_t* get_books_by_author_and_release_date(db_conn_t* connection, const char* author, const timestamp_t* release_date);
book_array_t* get_books_by_publisher_and_release_date(db_conn_t* connection, const char* publisher, const timestamp_t* release_date);
book_array_t* get_books_by_title_and_author_and_publisher(db_conn_t* connection, const char* title, const char* author, const char* publisher);
book_array_t* get_books_by_title_and_author_and_release_date(db_conn_t* connection, const char* title, const char* author, const timestamp_t* release_date);
book_array_t* get_books_by_title_and_publisher_and_release_date(db_conn_t* connection, const char* title, const char* publisher, const timestamp_t* release_date);
book_array_t* get_books_by_author_and_publisher_and_release_date(db_conn_t* connection, const char* author, const char* publisher, const timestamp_t* release_date);
loan_t* get_loan_by_id(db_conn_t* connection, const int id);
loan_t* get_loans_by_account_id(db_conn_t* connection, const int id);
loan_t* get_loans_by_book_id(db_conn_t* connection, const int id);

#endif