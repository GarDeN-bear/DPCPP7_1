#include "sql_query_builder.h"

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(std::string columnName_)
{
    if (columnNamesIsEmpty)
    {
        columnNames = columnName_;
        columnNamesIsEmpty = false;
    }
    else
    {
        columnNames += ", " + columnName_;
    }
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(std::string tableName_)
{
    tableName = tableName_;
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(std::string columnName_, std::string value_)
{
    if (whereConditionIsOne)
    {
        whereCondition += columnName_ + "=" + value_;
        whereConditionIsOne = false;
    }
    else
    {
        whereCondition += " AND " + columnName_ + "=" + value_;
    }
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& kv)
{
    for (const auto& el : kv)
    {
        if (whereConditionIsOne)
        {
            whereCondition += el.first + "=" + el.second;
            whereConditionIsOne = false;
        }
        else
        {
            whereCondition += " AND " + el.first + "=" + el.second;
        }
    }
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const std::vector<std::string>& columns)
{
    for (const auto& el : columns)
    {
        if (columnNamesIsEmpty)
        {
            columnNames = el;
            columnNamesIsEmpty = false;
        }
        else
        {
            columnNames += ", " + el;
        }
    }
    return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery()
{
    buildQuery = "SELECT";
    buildQuery += " " + columnNames + " FROM " + tableName + " WHERE " + whereCondition + ";";
    return buildQuery;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhere(std::string columnName_, std::string operator_, std::string value_)
{
    if (whereConditionIsOne)
    {
        whereCondition += columnName_ + operator_ + value_;
        whereConditionIsOne = false;
    }
    else
    {
        whereCondition += " AND " + columnName_ + operator_ + value_;
    }
    return *this;
}
