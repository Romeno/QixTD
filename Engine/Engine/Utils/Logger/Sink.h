#pragma once
#include "Engine/Utils/MeasureUnits/InfoSize.h"


class Sink
{
public:
	Sink();
	virtual ~Sink();

	virtual std::wstring GetP7InitString();

	void SetName( const std::wstring& name ) { m_name = name; }
	void Enable( bool enabled ) { m_enabled = enabled; }
	void SetVerb( int verb ) { m_verb = verb; }
	void SetMemoryPoolSize( size_t size ) { m_memoryPoolSize = size; }
	virtual bool GetUseCout() { return false; }
	virtual void SetUseCout(bool use) { }

	std::wstring		m_name;
	bool				m_enabled;
	int					m_verb;
	size_t				m_memoryPoolSize;		// in Kilobytes_
};


class BaicalSink : public Sink
{
public:
	typedef Sink super;

	BaicalSink();
	virtual ~BaicalSink();

	virtual std::wstring GetP7InitString();

	void SetServerAddress( const std::wstring& addr ) { m_serverAddress = addr; }
	void SetPort( int port ) { m_port = port; }
	void SetPacketSize( int size ) { m_packetSize = size; }
	void SetWindowSize( int size ) { m_windowSize = size; }
	void SetTransmissionTimeout( int timeout ) { m_transmissionTimeout = timeout; }

	std::wstring		m_serverAddress;		// NetBios, IPV4, IPV6 address
	int					m_port;					// default 9010
	int					m_packetSize;			// in bytes
	int					m_windowSize;			// in packets
	int					m_transmissionTimeout;	// in seconds
};


class FileSink : public Sink
{
public:
	typedef Sink super;

	FileSink();
	virtual ~FileSink();

	virtual std::wstring GetP7InitString();

	void SetFormat( const std::wstring& format ) { m_format = format; }
	void SetDir( const std::wstring& dir ) { m_dir = dir; }
	void SetRotationLogSize( int megabytes );			// sets log rotation by size in megabytes. ONLY ONE rotation type can be set
	void SetRotationTTL( int hours );					// sets log rotation by time to live in hours. ONLY ONE rotation type can be set
	void SetRotationMaxLogFiles( int max ) { m_maxLogs = max; }

	std::wstring			m_format;
	std::wstring			m_dir;
	std::wstring			m_roll;
	int						m_maxLogs;		// max log files in folder
};


class ConsoleSink : public Sink
{
public:
	typedef Sink super;

	ConsoleSink();
	virtual ~ConsoleSink();

	virtual std::wstring GetP7InitString();

	void SetFormat( const std::wstring& format ) { m_format = format; }
	virtual bool GetUseCout() { return m_useCout; }
	virtual void SetUseCout( bool use ) { m_useCout = use; }

	std::wstring			m_format;
	bool					m_useCout;
};




