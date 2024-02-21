#include "queries.h"

account_t* get_account_by_id(db_conn_t* connection, const int id)
{
	char buffer[QUERY_STRING_MAX_LENGTH];
	sprintf(buffer, "SELECT * FROM account_by_id(%d)", id);
	return perform_account_query(connection, buffer);
}

account_t* get_account_by_email(db_conn_t* connection, const char* email)
{
	char buffer[QUERY_STRING_MAX_LENGTH];
	sprintf(buffer, "SELECT * FROM account_by_email('%s')", email);
	return perform_account_query(connection, buffer);
}

account_array_t* get_accounts_by_book_id(db_conn_t* connection, const int id)
{
	char buffer[QUERY_STRING_MAX_LENGTH];
	sprintf(buffer, "SELECT * FROM account_by_book_id('%d')", id);
	return perform_account_array_query(connection, buffer);
}

account_t* get_account_by_loan_id(db_conn_t* connection, const int id)
{
	char buffer[QUERY_STRING_MAX_LENGTH];
	sprintf(buffer, "SELECT * FROM account_by_loan_id(%d)", id);
	return perform_account_query(connection, buffer);
}

book_t* get_book_by_id(db_conn_t* connection, const int id)
{
	char buffer[QUERY_STRING_MAX_LENGTH];
	sprintf(buffer, "SELECT * FROM book_by_id(%d)", id);
	return perform_book_query(connection, buffer);
}

book_array_t* get_books_by_account_id(db_conn_t* connection, const int id)
{
	char buffer[QUERY_STRING_MAX_LENGTH];
	sprintf(buffer, "SELECT * FROM books_by_account_id(%d)", id);
	return perform_book_array_query(connection, buffer);
}

book_t* get_book_by_loan_id(db_conn_t* connection, const int id)
{
	char buffer[QUERY_STRING_MAX_LENGTH];
	sprintf(buffer, "SELECT * FROM book_by_loan_id(%d)", id);
	return perform_book_query(connection, buffer);
}

book_array_t* get_books_by_title(db_conn_t* connection, const char* title)
{
	char buffer[QUERY_STRING_MAX_LENGTH];
	sprintf(buffer, "SELECT * FROM books_by_title(%s)", title);
	return perform_book_array_query(connection, buffer);
}

book_array_t* get_books_by_author(db_conn_t* connection, const char* author)
{
	char buffer[QUERY_STRING_MAX_LENGTH];
	sprintf(buffer, "SELECT * FROM books_by_author(%s)", author);
	return perform_book_array_query(connection, buffer);
}

book_array_t* get_books_by_publisher(db_conn_t* connection, const char* publisher)
{
	char buffer[QUERY_STRING_MAX_LENGTH];
	sprintf(buffer, "SELECT * FROM books_by_publisher(%s)", publisher);
	return perform_book_array_query(connection, buffer);
}

book_array_t* get_books_by_release_date(db_conn_t* connection, const timestamp_t* release_date)
{
	char string_timestamp[STRING_TIMESTAMP_MAX_LENGTH] = "";
	timestamp_to_string(string_timestamp, release_date);
	char buffer[QUERY_STRING_MAX_LENGTH];
	sprintf(buffer, "SELECT * FROM books_release_date(%s)", string_timestamp);
	return perform_book_array_query(connection, buffer);
}