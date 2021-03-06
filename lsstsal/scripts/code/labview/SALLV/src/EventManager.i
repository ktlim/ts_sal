// ============================================================================
//
// = CONTEXT
//   SALLV Generic Client for LabVIEW
//
// = FILENAME
//   EventManager.i
//
// = AUTHOR
//   Nicolas Leclercq - SOLEIL : SAL adaptation : Dave Mills - LSST
//
// ============================================================================

//=============================================================================
// EventManager::instance
//=============================================================================
LV_INLINE EventManager* EventManager::instance (void)
{
  return EventManager::instance_;
}

//=============================================================================
// EventManager::events_have_been_used
//=============================================================================
LV_INLINE bool EventManager::events_have_been_used (void)
{
  return events_have_been_used_;
}

//=============================================================================
// EventCallback::subsys_name
//=============================================================================
LV_INLINE const std::string& EventCallback::subsys_name (void)
{
  return dev_;
}

//=============================================================================
// EventCallback::attribute_name
//=============================================================================
LV_INLINE const std::string& EventCallback::attribute_name (void)
{
  return attr_;
}

//=============================================================================
// EventCallback::lv_evt_refnum
//=============================================================================
LV_INLINE LVUserEventRef EventCallback::lv_evt_refnum (void)
{
  return lv_evt_refnum_;
}





