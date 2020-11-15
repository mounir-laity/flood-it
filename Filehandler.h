#ifndef FILEHANDLER_H
#define FILEHANDLER_H

/*!
 * \brief The FileHandler class represents the class that reads records from the record files and
 * writes new records in the record file
 */
class FileHandler
{
public:

    /*!
     * \brief FileHandler Constructor for FileHandler with the correct settings
     * \param lines the number of lines of the board
     * \param columns the number of columns of the board
     * \param colors the number of colors of the board
     */
    FileHandler(unsigned lines, unsigned columns, unsigned colors);

    /*!
     * \brief readRecord reads the record from the records file for the current board
     * \return the record for that board size or 9999 if there's no record yet
     */
    int readRecord();

    /*!
     * \brief writeRecord overwrites the records file with the new record
     * \param record the new record for this board configurations
     */
    void writeRecord(int record);



private:

    unsigned lines;
    unsigned columns;
    unsigned colors;

};

#endif // FILEHANDLER_H
