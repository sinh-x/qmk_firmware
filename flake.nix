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
      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            # QMK and Python packages
            qmk
            python3
            python3Packages.qmk
            python3Packages.appdirs
            python3Packages.argcomplete
            python3Packages.colorama
            python3Packages.hid
            python3Packages.hjson
            python3Packages.jsonschema
            python3Packages.milc
            python3Packages.pygments
            python3Packages.pyserial
            python3Packages.pyusb
            python3Packages.pillow

            # Compilers and flashing tools
            gcc-arm-embedded
            avr-gcc
            avrlibc
            avrdude
            dfu-util
            dfu-programmer
            teensy-loader-cli

            # Additional tools
            git
            gnumake
          ];

          shellHook = ''
            echo "QMK development environment loaded!"
            echo "Available commands:"
            echo "  qmk setup"
            echo "  qmk compile -kb sofle -km sinh-x"
            echo "  qmk flash -kb sofle -km sinh-x"

            # Set QMK home if not already set
            export QMK_HOME=''${QMK_HOME:-$(pwd)}
            echo "QMK_HOME: $QMK_HOME"
          '';
        };
      }
    );
}
