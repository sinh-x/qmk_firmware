{
  description = "QMK development environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = nixpkgs.legacyPackages.${system};

        # Create a Python environment with QMK dependencies
        pythonEnv = pkgs.python3.withPackages (
          ps: with ps; [
            pip
            setuptools
            wheel
            pyserial
            pyusb
            pillow
            hjson
            jsonschema
            colorama
            pygments
            appdirs
            argcomplete
            hid
            milc
            # Add any other Python packages QMK might need
          ]
        );
      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            # Core QMK
            qmk

            # Python environment with all dependencies
            pythonEnv

            # AVR toolchain
            pkgsCross.avr.buildPackages.gcc
            pkgsCross.avr.buildPackages.binutils
            pkgsCross.avr.avrlibc

            # ARM toolchain
            gcc-arm-embedded

            # Flashing tools
            dfu-util
            dfu-programmer
            teensy-loader-cli
            avrdude

            # Build tools
            git
            gnumake
          ];

          shellHook = ''
            echo "QMK development environment loaded!"

            # Set QMK home
            export QMK_HOME=''${QMK_HOME:-$(pwd)}
            echo "QMK_HOME: $QMK_HOME"

            # Create a local virtual environment for any additional packages
            if [ ! -d ".venv" ]; then
              python -m venv .venv
              source .venv/bin/activate
              echo "Created virtual environment in .venv"
            else
              source .venv/bin/activate
              echo "Activated existing virtual environment"
            fi

            echo "Available compilers:"
            echo "  avr-gcc (from pkgsCross.avr)"
            echo "  arm-none-eabi-gcc (from gcc-arm-embedded)"
            echo ""
            echo "Try running 'qmk setup' now"
          '';
        };
      }
    );
}
