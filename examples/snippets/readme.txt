Follow the below description to execute examples in snippets folder.

snippets folder contains following examples
============================================
1. ble_central
2. ble_datalength
3. ble_dual_role
4. ble_heart_rate_profile
5. ble_ibeacon
6. ble_longrange_2mbps
7. ble_power_save
8. ble_privacy
9. ble_secureconnection
10. ble_white_list
11. hid_on_gatt
12. bt_power_save
13. bt_spp_dual_role_with_secure_pairing
14. bt_ble_dual_mode
15. ram_dump
16. access_point
17. calibration_app
18. cloud_apps
    |- aws_iot\device_shadow_logging_stats
	|- aws_iot\mqtt
	|- azure_iot
19. concurrent_mode
20. embedded_mqtt
21. enterprise_client
22. http_otaf
23. mqtt_client
24. power_save_deep_sleep
25. socket_select_app
26. station_ping
27. tcp_logging_stats
28. three_ssl_concurrent_client_sockets
29. tls_client
30. wlan_station_ble_bridge
31. wlan_station_ble_provisioning
32. wlan_station_ble_provisioning_aws

	
The above examples can be tested on
1. keil/STM32 platform and simplicity studio/EFR platform.
2. Only baremetal

snippets folder contains following examples in FreeRTOS only
==============================================================
	
1. ble_multiconnection_gatt_test  
2. wlan_https_bt_spp_ble_dual_role
3. wlan_throughput_bt_spp_ble_dual_role
	
The above examples can be tested on both 
1. keil/STM32 platform and simplicity studio/EFR platform.
2. In FreeRTOS only
	
4.bt_a2dp_source_with_avrcp

The above example can be tested on 
1. IAR/NXP RT595 platform.
2. In FreeRTOS only
	
Example folder contents
========================
1. 'projects' folder which has both keil and simplicity studio project files which are used to test the example.
2. 'resources' and 'readme.md' - documentaion for the example
3. source files

For ex: 
=======
ble_central/projects consists of two projects
-for Keil - please access the below project file for executing the example.
	ble_central-nucleo-f411re.uvprojx
-for simplicity studio - please access below project file for executing the example.
	ble_central-brd4180b-mg21.slsproj
