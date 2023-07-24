# Technical debt monsters

## Table of Contents
- [Introduction]
- [Setting up the project (Getting started)]
- [Updating the dependencies]
- [Generating Documentation & Running Tests]
- [Allowing other data sources (Extending the project)]

## Introduction

This project is a proof of concept.
It introduces gamification in technical debt management by giving developers mascots
(technical debt monsters) with strengths based on metrics related to technical debt items
in the backlog.

The monsters appearence changes depending on its level.

The monsters values are based on:
- Attack: The amount of technical debt items closed by a developer
- Defense: The amount of technical debt items opened by a developer
- Speed: The cumulated amount of watchers on all issues opened by a developer
- Level: The average value of the above three

## Setting up the project (Getting started)

Instructions are provided for Windows.

To set up the project please follow the steps below:
1. Make sure the following are installed on your system:
	- Microsoft Visual Studio Community 2022 (64-bit) - Preview
Version 17.7.0 Preview 4.0 or newer. [Download](https://visualstudio.microsoft.com/de/vs/) (Please make sure to select the "Desktop development with C++" workload in the installer.)
	- Vcpkg. [Install instructions](https://vcpkg.io/en/getting-started.html) (You do not need to run any install commands for packages in the console. This is handled by the build scrips. But, please make sure to run `vcpkg integrate install` at least once before opening the td-mon project.)

2. Clone the Td-Mon [git repository](https://github.com/Maxomann/TDMon) to your pc.

3. Open the project using the "open folder" command in Visual Studio.

4. Compile and run.

## Updating the dependencies

To update all dependencies at once, please follow the steps below:

1. Make sure your cloned vcpkg repository is up-to-date. If in doubt, run `git pull` in the folder where you cloned the vcpkg repository.
2. Go to the folder of the Td-Mon repository and open `vcpkg.json` in any text editor of your choice.
3. Replace the value for `builtin-baseline` with the hash value of the newest commit in the vcpkg repository (Get the hash from [here](https://github.com/microsoft/vcpkg/commits/master)).
4. Re-generate CMake cache in Visual Studio. (This usually happens automatically.)

To update individual dependencies please see the vcpkg [documentation](https://learn.microsoft.com/en-us/vcpkg/users/versioning.concepts).

## Generating Documentation & Running Tests

For generating beautiful documentation, I recommend running [Doxygen](https://www.doxygen.nl/index.html) in the project folder.

🔴❗TODO: Running tests❗🔴

## Allowing other data sources (Extending the project)

By default, td-mon supports connecting to a technical debt dataset database in sqlite format.
To enable other data sources (for example Jira), please follow the steps below:

1. Implement a custom td-mon factory. As an example, please look at `TechnicalDebtDatasetConnectableDefaultTdMonFactory`. It is recommended that your custom factory implements (inherits from) the following interfaces:
	- `TdMonFactory` (Necessary)
	- `ConnectableToDataSources` (Optional, but recommended)
	- A custom interface for a container that allows storing the information you need to access your specific data-source. Like the currently existing `TechnicalDebtDatasetAccessInformationContainer`, but modified to suit your needs. You might call your interface `JiraAccessInformationContainer`. (Optional, but recommended)
2. Implement a custom setup menu. As an example, please look at the currently existing `TechnicalDebtDatasetSetupMenu`. Your setup menu must inherit from `ApplicationState`. The setup menu handles the gui needed to feed login data (or other information) to your factory. Your setup menu must take one constuctor parameter: a reference to the `TdMonFactory` implementation you created in step 1. These constraints are checked at compile time. Compilation will fail if theses contraints are not adhered to.
3. Inject your newly created classes as template parameters in the `Core` in the `main.cc` file. The project is based on dependecy injection. You only need to modify the `main.cc` file.
4. Compile and run.
