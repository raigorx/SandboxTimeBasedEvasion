# Virtualization/Sandbox Evasion: Time Based

Based on <https://shubakki.github.io/posts/2022/12/detecting-and-evading-sandboxing-through-time-based-evasion/>

## What is this?

Simple examples of time based evasion on windows using CPU cycles and _KUSER_SHARED_DATA

## What is Virtualization/Sandbox Evasion: Time Based Evasion ?

<https://attack.mitre.org/techniques/T1497/003/>

## Code structure

- **CPU_Cycles** get cpu cycles, virtual machines burn more CPU than bare metal
- **KSYSTEM_TIME** get Unix timestamp via _KUSER_SHARED_DATA to simulate sleep

## Notes

Cpu Cycles doesn't work on windows sandbox neither on docker windows containers both are so fast that is hard to get the difference

<https://learn.microsoft.com/en-us/windows/security/threat-protection/windows-sandbox/windows-sandbox-overview>
<https://learn.microsoft.com/en-us/virtualization/windowscontainers/quick-start/run-your-first-container>
