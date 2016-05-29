#pragma once

class TabRecord {
private:
	float key;
	void* data;
public:
	TabRecord(float key, void *&data);
	float getKey() const;
	void* getData() const;
};

class Table {
protected:
	int size;
	int count;
	int currentPosition;
public:
	Table(int size);
	virtual ~Table(){};

	virtual TabRecord* search(float key) = 0;
	virtual int insert(float key, void* data) = 0;
	virtual int remove(float key) = 0;
	virtual TabRecord* pull(float key) = 0;

	virtual TabRecord* searchMin() = 0;
	virtual TabRecord* searchMax() = 0;
	
	int isEmpty() const;
	int isFull() const;
	int getDataCount() const;
	virtual int reset();
	virtual int getNext();
	virtual int isTableEnded();
	
	virtual float getKey() const = 0;
	virtual void* getData() const = 0;
};

class ScanTable : public Table {
protected:
	TabRecord** records;
public:
	ScanTable(int size);
	virtual ~ScanTable();

	virtual TabRecord* search(float key);
	virtual int insert(float key, void* data);
	virtual int remove(float key);
	virtual TabRecord* pull(float key);

	virtual TabRecord* searchMin();
	virtual TabRecord* searchMax();

	virtual float getKey() const;
	virtual void* getData() const;
};

class SortTable : public ScanTable {
public:
	SortTable(int size);
	virtual ~SortTable(){};

	virtual TabRecord* search(float key);
	virtual int insert(float key, void* data);
	virtual int remove(float key);
	virtual TabRecord* pull(float key);

	virtual TabRecord* searchMin();
	virtual TabRecord* searchMax();
};