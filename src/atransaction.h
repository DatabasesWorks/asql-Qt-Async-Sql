#ifndef ATRANSACTION_H
#define ATRANSACTION_H

#include <QSharedPointer>

#include <adatabase.h>
#include <aqsqlexports.h>

class ATransactionPrivate;
class ASQL_EXPORT ATransaction
{
public:
    ATransaction();
    ~ATransaction();

    ATransaction(const ADatabase &db);

    ATransaction(const ATransaction &other);

    ATransaction &operator =(const ATransaction &copy);

    /*!
     * \brief begin a transaction, this operation usually succeeds,
     * but one can hook up a callback to check it's result.
     *
     * \param cb
     */
    void begin(AResultFn cb = {});

    /*!
     * \brief commit a transaction, this operation usually succeeds,
     * but one can hook up a callback to check it's result.
     *
     * \param cb
     */
    void commit(AResultFn cb = {});

    /*!
     * \brief rollback a transaction, this operation usually succeeds,
     * but one can hook up a callback to check it's result.
     *
     * \param cb
     */
    void rollback(AResultFn cb = {});

private:
    QSharedPointer<ATransactionPrivate> d;
};

#endif // ATRANSACTION_H
