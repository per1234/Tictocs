// STL includes
// C includes
// Library includes
// Project includes
#include <RtcEvent.h>

const IRtc* RtcEvent::rtc = NULL;

/****************************************************************************/

void RtcEvent::update(void)
{
  if ( active && rtc->is_after(when) )
  {
    active = false;
    emit(signal_what);
  }
}

/****************************************************************************/
RtcEvent::RtcEvent(Connector& _conn,uint32_t _when,uint8_t _signal_what):
	Connectable(_conn), when(_when), signal_what(_signal_what), active(false)
{
}

/****************************************************************************/

void RtcEvent::begin(void)
{
  if ( rtc )
    active = ! rtc->is_after(when);
}

/****************************************************************************/

void RtcEvent::setRtc(const IRtc* _rtc)
{
  rtc = _rtc;
}

/****************************************************************************/

// vim:cin:ai:sts=2 sw=2 ft=cpp
