#pragma once
#include <iostream>
#include <vector>
#include <map>

class SqlSelectQueryBuilder
{
public:
	SqlSelectQueryBuilder& AddColumn(std::string columnName_) ;
	SqlSelectQueryBuilder& AddFrom(std::string tableName_) ;
	SqlSelectQueryBuilder& AddWhere(std::string columnName_, std::string value_) ;
	SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) ;
	SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) ;
	std::string BuildQuery() ;

protected:
	std::string columnNames = "*";
	bool columnNamesIsEmpty = true;

	std::string tableName = "";

	std::string whereCondition = "";
	bool whereConditionIsOne = true;

	std::string buildQuery = "\"SELECT";
};

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder
{
public:
	using SqlSelectQueryBuilder::AddColumn;
    using SqlSelectQueryBuilder::AddFrom;
    using SqlSelectQueryBuilder::AddWhere;
    using SqlSelectQueryBuilder::AddColumns;
	AdvancedSqlSelectQueryBuilder& AddWhere(std::string columnName_, std::string operator_, std::string value_);
};