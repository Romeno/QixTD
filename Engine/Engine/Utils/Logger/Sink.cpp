#include "stdafx.h"
#include "Sink.h"
#include "GTypes.h"


Sink::Sink()
	: m_name()				// default name of current process
	, m_enabled(true)	
	, m_verb(-1)
	, m_memoryPoolSize(0)	// min 16 Kb, default 4096 Kb
{

}


Sink::~Sink()
{

}


std::wstring Sink::GetP7InitString()
{
	std::wstring ret;

	if ( !m_name.empty() )
	{
		ret += TM("/P7.Name=") + m_name;
	}

	return ret;
}


BaicalSink::BaicalSink()
	: super()

	, m_serverAddress()
	, m_port(0)						// default 9010
	, m_packetSize(0)				// default 512
	, m_windowSize(0)				// min-max 1 - ((pool size / packet size) / 2)
	, m_transmissionTimeout(0)
{

}


BaicalSink::~BaicalSink()
{

}


std::wstring BaicalSink::GetP7InitString()
{
	std::wstring ret = super::GetP7InitString();

	ret += TM("/P7.Sink=Baical");

	if ( !m_serverAddress.empty() )
	{
		ret += TM("/P7.Addr=") + m_serverAddress;
	}

	if ( m_port )
	{
		ret += TM("/P7.Port=") + std::to_wstring( m_port );
	}
	
	if ( m_packetSize )
	{
		ret += TM("/P7.PSize=") + std::to_wstring( m_packetSize );
	}

	if ( m_windowSize )
	{
		ret += TM("/P7.Window=") + std::to_wstring( m_windowSize );
	}

	if ( m_transmissionTimeout )
	{
		ret += TM("/P7.Eto=") + std::to_wstring( m_transmissionTimeout );
	}

	return ret;
}


FileSink::FileSink()
	: super()

	, m_format()
	, m_dir()
	, m_roll()
	, m_maxLogs(0)		// default 0 - OFF, max 4096
{

}


FileSink::~FileSink()
{

}


std::wstring FileSink::GetP7InitString()
{
	std::wstring ret = super::GetP7InitString();

	ret += TM("/P7.Sink=FileTxt");

	if ( !m_format.empty() )
	{
		ret += TM("/P7.Format=") + m_format;
	}

	if ( !m_dir.empty() )
	{
		ret += TM("/P7.Dir=") + m_dir;
	}

	if ( !m_roll.empty() )
	{
		ret += TM("/P7.Roll=") + m_roll;
	}

	if ( m_maxLogs )
	{
		ret += TM("/P7.Files=") + std::to_wstring(m_maxLogs);
	}

	return ret;
}

void FileSink::SetRotationLogSize( int megabytes )
{
	m_roll = std::to_wstring( megabytes ) + TM("mb");
}


void FileSink::SetRotationTTL( int hours )
{
	m_roll = std::to_wstring( hours ) + TM("hr");
}


ConsoleSink::ConsoleSink()
	: super()

	, m_format()
	, m_useCout(false)
{

}


ConsoleSink::~ConsoleSink()
{

}


std::wstring ConsoleSink::GetP7InitString()
{
	std::wstring ret = super::GetP7InitString();

	ret += TM("/P7.Sink=Console");

	if ( !m_format.empty() )
	{
		ret += TM("/P7.Format=") + m_format;
	}

	return ret;
}
