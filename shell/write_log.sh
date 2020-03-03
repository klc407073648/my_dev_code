#!/bin/bash
LOG_DIR=/home/klc/logpath
LOG_FILE=$LOG_DIR/my.log


function write_log()
{
  if [ ! -d ${LOG_DIR} ];then
	 mkdir -p ${LOG_DIR} 
  fi
  
  if [ ! -d ${LOG_FILE} ];then
	 touch  ${LOG_FILE} 
  fi
  
  fileCount=`ls ${LOG_DIR}/*.log |wc -l`
  
  if [ ${fileCount} -gt 10 ];then
     find ${LOG_DIR} -type f |xargs ls -tr | head -5 | xargs rm
  fi
  
  echo -n `date "+%Y%M %T"` >>${LOG_FILE}
  echo "$1" >>${LOG_FILE}
  
  return 0
}

write_log "test log"
write_log "--------"

